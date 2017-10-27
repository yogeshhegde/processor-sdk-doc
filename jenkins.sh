#!/bin/bash

ARTIFACTS="$(dirname $(readlink -m $0))/artifacts"
OUTPUT="${ARTIFACTS}/output"
LOGS="${ARTIFACTS}/logs"
BUILDDIR="${OUTPUT}/html"


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

# build targets
echo "html/index.html" > "${BUILD_TARGETS}"

# do the thing
make BUILDDIR="${BUILDDIR}" 2>&1 | tee "${LOGS}/make.log"

# provide link to output
echo "${BUILDDIR}" | sed -e "s|^${ARTIFACTS}|${BUILD_URL}/artifacts/|g" | \
                     sed -e 's|//*|/|g' -e 's|^http:/*|http://|g' > "${BUILD_NOTES}"
