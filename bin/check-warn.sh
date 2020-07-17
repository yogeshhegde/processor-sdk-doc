#!/bin/bash
### PSDK-doc check new build WARNINGs

trap restore_branch 1 2 3 6 15

usage()
{
	echo "Build and check if git branch or commit <NEW> generates" \
	     "any new build WARNING(s) based on git branch or commit <OLD>."
	echo
	echo "check-warn.sh <-d | --device DEV> [-o | --os OS] <-a OLD> <-b NEW> [-h | --help]"
	echo
	echo -e "\t-d | --device DEV: build for device-family DEV"
	echo -e "\t-o | --os OS:      build for os OS, default: linux"
	echo -e "\t-a OLD:            git branch or commit ID OLD as the base, 'HEAD' is acceptable"
	echo -e "\t-b NEW:            git branch or commit ID NEW for checking WARNING(s), 'HEAD' is acceptable"
	echo -e "\t-h | --help:       this message"
	echo
	exit $1
}

restore_branch()
{
	[[ -z "$_cbr" ]] || git checkout $_cbr
}

### main() ###

while [ $# -gt 0 ]; do
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

git checkout ${_old} || exit 10

make DEVFAMILY=${_dev} OS=${_os} clean
make DEVFAMILY=${_dev} OS=${_os} config > _a.log 2>&1 || exit 12
make DEVFAMILY=${_dev} OS=${_os} >> _a.log 2>&1 || exit 13
grep "WARNING:" _a.log > _a-warn.log

git checkout ${_new} || exit 20

make DEVFAMILY=${_dev} OS=${_os} clean
make DEVFAMILY=${_dev} OS=${_os} config > _b.log 2>&1 || exit 22
make DEVFAMILY=${_dev} OS=${_os} >> _b.log 2>&1 || exit 23
grep "WARNING:" _b.log > _b-warn.log

restore_branch

diff --changed-group-format="%>" --unchanged-group-format="" \
	_a-warn.log _b-warn.log > _new-warn.log

_num=$(cat _new-warn.log | wc -l)

echo
echo "Found $_num new build WARNING(s)."
echo

if [[ $_num != "0" ]]; then
	cat _new-warn.log
fi

