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
TEMP="${ARTIFACTS}/temp"
OS="${1:-all}"
LOGS="${ARTIFACTS}/logs"


REPO_REV="${ARTIFACTS}/repo-revs.txt"
BUILD_TARGETS="${OUTPUT}/build_targets"
BUILD_NOTES="${ARTIFACTS}/build-notes.txt"


UBUNTU_PACKAGES="python-sphinx"


rm -rf "${TEMP}"
mkdir -pv "${ARTIFACTS}" "${OUTPUT}" "${LOGS}" "${TEMP}"

# Set up host
sudo apt-get -y install ${UBUNTU_PACKAGES}

# Update submodule
echo "Update submodule..."
git submodule init
git submodule update

# repo-revs.txt
repo=`git config --get remote.origin.url | tr ':' ';'`
commit=`git rev-parse HEAD`
branch=`git branch | grep "^\*" | sed -e 's|^* ||g'`
comment=""

repo_rev_line="${repo}:${commit}:${branch}:${comment}"
echo "${repo_rev_line}" >> "${REPO_REV}"

# Get the version number from processor-sdk-config git repo
RELEASE="$(cat version.txt)"
RELEASE=${RELEASE//_/.}
CONFIG_REPO='https://bitbucket.itg.ti.com/scm/processor-sdk/processor-sdk-config.git'
if [[ ${branch} == next ]]; then
    # For the next branch, use the same version number as in the nightly builds
    git clone $CONFIG_REPO
    VERSION="$(./processor-sdk-config/bin/get_version.sh -d ./processor-sdk-config/bin -r ${RELEASE})"
else
   # For the other branches, use the latest SDF version number for the release
   TAG_PREFIX='DEV.PROCESSOR-SDK.'
   VERSION="$(git ls-remote --tags "$CONFIG_REPO" "$TAG_PREFIX$RELEASE"\* | sed -ne 's|.*'"$TAG_PREFIX"'||p' | sort | tail -1)"
fi
VERSION=${VERSION//./_}

build_doc()
{
    # build targets
    OS=$1
    BUILDDIR="${OUTPUT}/processor-sdk-${OS}/esd/docs/${VERSION}"
    echo "processor-sdk-${OS}/esd/docs/${VERSION}/${OS}/index.html" >> "${BUILD_TARGETS}"

    # do the thing
    make config DEVFAMILY="GEN" OS="${OS}" VERSION="${VERSION}" 2>&1 | tee -a "${LOGS}/make.log"
    make BUILDDIR="${BUILDDIR}" DEVFAMILY="GEN" OS="${OS}" VERSION="${VERSION}" 2>&1 | tee -a "${LOGS}/make.log"

    # provide link to output
    echo "${BUILDDIR}" | sed -e "s|^${ARTIFACTS}|${BUILD_URL}/artifacts/|g" | \
                         sed -e 's|//*|/|g' -e 's|^http:/*|http://|g' >> "${BUILD_NOTES}"

    # copy repo-revs.txt to output directory
    cp $REPO_REV $BUILDDIR

    rm -rf ${BUILDDIR}/${OS}/processor-sdk-${OS}-docs.tar.gz
    cp -r ${BUILDDIR} ${TEMP}/processor-sdk-${OS}-docs-${VERSION}
    CURRDIR=$PWD
    cd ${TEMP}
    tar -czvf processor-sdk-${OS}-docs.tar.gz processor-sdk-${OS}-docs-${VERSION}
    cp processor-sdk-${OS}-docs.tar.gz ${BUILDDIR}/${OS}
    cd ${CURRDIR}
}

if [[ ${OS} == all ]]; then
    build_doc linux
    build_doc rtos
    build_doc android
else
    build_doc ${OS}
fi

