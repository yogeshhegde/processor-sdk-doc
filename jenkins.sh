#!/bin/bash

usage() {
    cat << EOF

  Usage:
         $0 <target_os> <device_family>
		target_os:     linux, rtos, android, all
		device_family: GEN, CORESDK, AM335X, AM437X, AM64X, all

EOF
}

if [ "$1" ]; then
case "$1" in
    all) echo "Build doc for all: linux/rtos/android and am64x"
        ;;
    linux) echo "Build doc for linux"
        ;;
    rtos) echo "Build doc for rtos"
        ;;
    android)
	if [[ "$2" == "GEN" ]]; then
	    echo "Build doc for android"
	else
	    echo "Android doc build is not available for $2"
	    usage
	    exit
        fi
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
DEV="${2:-all}"
LOGS="${ARTIFACTS}/logs"


REPO_REV="${ARTIFACTS}/repo-revs.txt"
BUILD_TARGETS="${OUTPUT}/build_targets"
BUILD_NOTES="${ARTIFACTS}/build-notes.txt"


UBUNTU_PACKAGES="python-sphinx"


rm -rf "${TEMP}"
mkdir -pv "${ARTIFACTS}" "${OUTPUT}" "${LOGS}" "${TEMP}"

# Set up host
which sphinx-build > /dev/null || sudo apt-get -y install ${UBUNTU_PACKAGES}

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
CONFIG_REPO='ssh://git@bitbucket.itg.ti.com/processor-sdk/processor-sdk-config.git'
if [[ ${branch} == next ]]; then
    # For the next branch, use the same version number as in the nightly builds
    git clone $CONFIG_REPO
    VERSION="$(./processor-sdk-config/bin/get_version.sh -d ./processor-sdk-config/bin -r ${RELEASE})"
else
   # For the other branches, use the latest SDF version number for the release
   TAG_PREFIX='DEV.PROCESSOR-SDK.'
   VERSION="$RELEASE.$(git ls-remote --tags "$CONFIG_REPO" "$TAG_PREFIX$RELEASE"\* | sed -ne 's|.*'"$TAG_PREFIX$RELEASE."'||p' | sort -n | tail -1)"
fi
ROOT_VERSION=${VERSION//./_}

build_doc()
{
    # build targets
    OS=$1
    DEV=$2

    release_path=''
    if [[ "$DEV" == "AM64X" || "$DEV" == "AM335X" || "$DEV" == "AM437X" ]]; then
            release_path="/devices/${DEV}"
            if ["$DEV" == "AM64X"]; then
                VERSION="$(cat source${release_path}/version.txt)"
	    else
                VERSION="$(cat source${release_path}/${OS}/version.txt)"
            fi
    else
	    VERSION=${ROOT_VERSION}
    fi

    if [[ "$DEV" == "GEN" ]]; then
            BUILDNAME="processor-sdk-${OS}"
            os_path="/${OS}"
    else
            BUILDNAME="processor-sdk-${OS}-${DEV}"
            os_path="/${OS}"
    fi

    BUILDDIR="${OUTPUT}/${BUILDNAME}/esd/docs/${VERSION}"
    echo "${BUILDNAME}/esd/docs/${VERSION}${release_path}${os_path}/index.html" >> "${BUILD_TARGETS}"

    # do the thing
    make config DEVFAMILY="${DEV}" OS="${OS}" VERSION="${VERSION}" 2>&1 | tee -a "${LOGS}/make.log"
    make BUILDDIR="${BUILDDIR}" DEVFAMILY="${DEV}" OS="${OS}" VERSION="${VERSION}" 2>&1 | tee -a "${LOGS}/make.log"

    # provide link to output
    echo "${BUILDDIR}" | sed -e "s|^${ARTIFACTS}|${BUILD_URL}/artifacts/|g" | \
                         sed -e 's|//*|/|g' -e 's|^http:/*|http://|g' >> "${BUILD_NOTES}"

    # copy repo-revs.txt to output directory
    cp $REPO_REV $BUILDDIR

    rm -rf ${BUILDDIR}/${OS}/${BUILDNAME}-docs.tar.gz
    cp -r ${BUILDDIR} ${TEMP}/${BUILDNAME}-docs-${VERSION}
    CURRDIR=$PWD
    cd ${TEMP}
    tar -czvf ${BUILDNAME}-docs.tar.gz ${BUILDNAME}-docs-${VERSION}
    cp ${BUILDNAME}-docs.tar.gz ${BUILDDIR}/${OS}
    cd ${CURRDIR}
}

if [[ ${OS} == all ]]; then
    for dev in "GEN" "AM335X" "AM437X"; do
	build_doc linux $dev
	build_doc rtos $dev
	if [[ "$dev" == "GEN" ]]; then
	    build_doc android $dev
	fi
    done
    # build AM64X
    build_doc linux AM64X
    # build J7
    build_doc linux J7
    # build CORESDK
    build_doc linux CORESDK
else
    build_doc ${OS} ${DEV}
fi

