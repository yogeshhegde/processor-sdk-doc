#!/bin/bash
sourcedir=$1

# install pandoc
sudo apt-get -y install pandoc

# get the file list
filelist=$(grep -rl ".. http://processors.wiki" --include \*.rst $sourcedir)

# call ./wiki2rst-process.sh to do the conversion
for file in $filelist; do
    wikiurlline=$(cat $file | grep ".. http://processors.wiki")
    wikiurl="$(sed -n 's/^.*http/http/p'<<<$wikiurlline)"
    echo $file
    echo $wikiurl

    ./bin/wiki2rst-process.sh $wikiurl $file
done
