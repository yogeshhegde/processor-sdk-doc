#!/bin/bash

usage() {
    cat << EOF

  Usage:
         $0 <target_os: linux, rtos, android, all>

EOF
}

if [ "$1" ]; then
case "$1" in
    all) echo "Build doc for all: linux/rtos/android"
        ;;
    linux) echo "Build doc for linux"
        ;;
    rtos) echo "Build doc for rtos"
        ;;
    android) echo "Build doc for android"
        ;;
    *) echo "Wrong argument $1"
       usage
       exit
        ;;
esac
fi

ARTIFACTS="$(dirname $(readlink -m $0))/artifacts"
OUTPUT="${ARTIFACTS}/output"
OS="${1:-all}"
LOGS="${ARTIFACTS}/logs"


REPO_REV="${ARTIFACTS}/repo-revs.txt"
BUILD_TARGETS="${OUTPUT}/build_targets"
BUILD_NOTES="${ARTIFACTS}/build-notes.txt"


UBUNTU_PACKAGES="python-sphinx"


mkdir -pv "${ARTIFACTS}" "${OUTPUT}" "${LOGS}"

# Set up host
sudo apt-get -y install ${UBUNTU_PACKAGES}

# repo-revs.txt
repo=`git config --get remote.origin.url | tr ':' ';'`
commit=`git rev-parse HEAD`
branch=`git branch | grep "^\*" | sed -e 's|^* ||g'`
comment=""

repo_rev_line="${repo}:${commit}:${branch}:${comment}"
echo "${repo_rev_line}" >> "${REPO_REV}"

build_doc()
{
    # build targets
    OS=$1
    BUILDDIR="${OUTPUT}/${OS}/html"
    echo "${OS}/html/${OS}/index.html" >> "${BUILD_TARGETS}"

    # do the thing
    make BUILDDIR="${BUILDDIR}" OS="${OS}" 2>&1 | tee -a "${LOGS}/make.log"

    # provide link to output
    echo "${BUILDDIR}" | sed -e "s|^${ARTIFACTS}|${BUILD_URL}/artifacts/|g" | \
                         sed -e 's|//*|/|g' -e 's|^http:/*|http://|g' >> "${BUILD_NOTES}"
}

if [[ ${OS} == all ]]; then
    build_doc linux
    build_doc rtos
    build_doc android
else
    build_doc ${OS}
fi

