#!/bin/bash

# Search for files mentioned in device toc configs that no longer exist.
# Then print what they are and where they are mentioned.

sort -u configs/*/*_toc.txt | rg '^[^\s#]' | \
	while IFS= read -r line
	do
		if ! [ -e "source/${line}.rst" ]; then
			echo "***"
			rg -i "^\s*${line}\s*$" configs/*/*_toc.txt
		fi
	done
