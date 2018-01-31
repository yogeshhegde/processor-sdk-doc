#!/bin/bash
sourcedir=$1
listoutput=$2

# get the file list
filelist=$(grep -rl ".. http://processors.wiki" --include \*.rst $sourcedir)

rm -f $listoutput

for file in $filelist; do
    wikiurlline=$(cat $file | grep ".. http://processors.wiki")
    wikiurl="$(sed -n 's/^.*http/http/p'<<<$wikiurlline)"
    echo $file >> $listoutput
    echo $wikiurl >> $listoutput
done
