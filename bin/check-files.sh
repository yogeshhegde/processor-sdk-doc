#!/bin/bash

# A script to check for, and list, files that exist in the source directory that
# meet both of the following conditions:
# 
# 	1. Are not rst files.
# 	2. Are not referenced by any other files in the source directory.

find "source/" ! -name '*.rst' ! -name 'version.txt' -type f -print0 |
	while IFS= read -r -d '' file_name; do
		if ! rg -q -i "$(basename "$file_name")" "source/"; then
			echo "$file_name"
		fi
	done
