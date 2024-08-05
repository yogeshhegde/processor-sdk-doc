#!/bin/bash
### PSDK-doc check new build WARNINGs

HELP_STRING="
Build and check if git branch or commit <NEW> generates any new build WARNING(s)
based on git branch or commit <OLD>.

check-warn.sh [OPTIONS]

BUILD OPTIONS:
  -d, --device DEV   build for device-family DEV
  -o, --os OS        build for os OS, default: linux

DIFF OPTIONS:
  -a OLD             git branch or commit ID OLD as the base, 'HEAD' is
                     acceptable
  -b NEW             git branch or commit ID NEW for checking WARNING(s), 'HEAD'
                     is acceptable

OTHER OPTIONS:
  -h, --help         this message
"

trap restore_branch 1 2 3 6 15

usage()
{
	echo "${HELP_STRING}"
	exit "$1"
}

restore_branch()
{
	[[ -z "$_cbr" ]] || git checkout "$_cbr"
}

### main() ###

while [ "$#" -gt 0 ]; do
	case $1 in
	-h | --help) usage 0;;
	-d | --device) shift; _dev=$1; shift;;
	-o | --os) shift; _os=$1; shift;;
	-a) shift; _old=$1; shift;;
	-b) shift; _new=$1; shift;;
	*) shift;;
	esac
done

[[ -n "$_dev" ]] || usage 1
[[ -n "$_old" && -n "$_new" ]] || usage 2
[[ -n "$_os" ]] || _os=linux

if [[ "$(head -1 Makefile 2> /dev/null)" != "# Makefile for Sphinx"* ]]
then
	echo "Error: Not in the top directory"
	exit 3
fi

# do nothing if current workspace is not clean
if [[ -n "$(git status --porcelain --untracked-files=no | grep -v swtoolsdev)" ]]
then
	echo "Error: Current workspace has uncommitted changes"
	exit 4
fi

# do nothing if target ${_new} doesn't exist,
# don't wait for it fails after ${_old} was built
if ! git cat-file -t "${_new}" > /dev/null 2>&1; then
	echo "${_new} not found"
	exit 5
fi

# convert 'HEAD' to its commit ID
if [[ "$_new" == "HEAD" ]]; then
	_new=$(git rev-parse HEAD)
fi
if [[ "$_old" == "HEAD" ]]; then
	_old=$(git rev-parse HEAD)
fi
	 

# get current branch name or commit ID
_cbr=$(git branch | sed -n '/\* /s///p')
if [[ $_cbr == "(HEAD detached"* ]]; then
	_cbr=$(git rev-parse HEAD)
fi

git checkout "${_old}" || exit 10

mkdir -p build

make DEVFAMILY="${_dev}" OS="${_os}" clean
make DEVFAMILY="${_dev}" OS="${_os}" config > build/_a.log 2>&1 || exit 12
make DEVFAMILY="${_dev}" OS="${_os}" >> build/_a.log 2>&1 || exit 13
grep "WARNING:" build/_a.log > build/_a-warn.log

git checkout "${_new}" || exit 20

make DEVFAMILY="${_dev}" OS="${_os}" clean
make DEVFAMILY="${_dev}" OS="${_os}" config > build/_b.log 2>&1 || exit 22
make DEVFAMILY="${_dev}" OS="${_os}" >> build/_b.log 2>&1 || exit 23
grep "WARNING:" build/_b.log > build/_b-warn.log

restore_branch

diff --changed-group-format="%>" --unchanged-group-format="" \
	build/_a-warn.log build/_b-warn.log > build/_new-warn.log

_num=$(cat build/_new-warn.log | wc -l)

echo
echo "Found $_num new build WARNING(s)."
echo

if [[ $_num != "0" ]]; then
	cat build/_new-warn.log
fi

