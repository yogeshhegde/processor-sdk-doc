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

save_branch()
{
	# get current branch name or commit ID
	_cbr=$(git branch | sed -n '/\* /s///p')
	if [[ "$_cbr" == "(HEAD detached"* ]]; then
		_cbr=$(git rev-parse HEAD)
	fi
}

restore_branch()
{
	[ -z "$_cbr" ] || git checkout "$_cbr"
}

summary()
{
	local _num

	rm -f build/_new-warn.log
	diff --changed-group-format="%>" --unchanged-group-format="" \
		build/_a-warn.log build/_b-warn.log > build/_new-warn.log

	_num=$(wc -l build/_new-warn.log)

	echo
	echo "Found $_num new build WARNING(s)."
	echo

	if [ "$_num" != "0" ]; then
		cat build/_new-warn.log
	fi
}

generate_log()
{
	local git_hash log_name log_path warning_log_path

	git_hash=$1
	log_name=$2

	log_path="build/${log_name}.log"
	warning_log_path="build/${log_name}-warn.log"

	git checkout "${git_hash}" || exit 10

	mkdir -p build

	rm -f "${log_path}" "${warning_log_path}"
	make DEVFAMILY="${_dev}" OS="${_os}" clean
	make DEVFAMILY="${_dev}" OS="${_os}" config >> "${log_path}" 2>&1 || exit 12
	make DEVFAMILY="${_dev}" OS="${_os}" >> "${log_path}" 2>&1 || exit 13
	grep "WARNING:" "${log_path}" > "${warning_log_path}"
}

rev-parse()
{
	local rev
	if ! rev=$(git rev-parse "$1"); then
		printf '%s\n' 'Unable to parse given revisions:'
		printf '  %s\n' "$1"
		exit 2
	fi
	echo "$rev"
}

main()
{
	if [[ "$(head -1 Makefile 2> /dev/null)" != "# Makefile for Sphinx"* ]]
	then
		echo "Error: Not in the top directory"
		exit 3
	fi

	# do nothing if current workspace is not clean
	if [ -n "$(git status --porcelain --untracked-files=no)" ]
	then
		echo "Error: Current workspace has uncommitted changes"
		exit 4
	fi

	save_branch

	_old=$(rev-parse "${_old}")
	_new=$(rev-parse "${_new}")

	generate_log "${_old}" "_a"
	generate_log "${_new}" "_b"

	restore_branch
	summary
}

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

[ -n "$_dev" ] || usage 1
[ -n "$_os" ] || _os=linux

if [ -z "${_new}" ] || [ -z "${_old}" ]; then
	usage 2
fi

main
