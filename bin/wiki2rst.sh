#!/bin/bash

rst_wiki_list=$1

while IFS='' read -r line1 || [[ -n "$line1" ]]; do
    file="$line1"
    read -r line2
    wikiurl="$line2"
   #./bin/wiki2rst-convert.sh $wikiurl $file
   #./bin/wiki2rst-pre-process.sh $file
    ./bin/wiki2rst-image.sh $wikiurl $file
done < $rst_wiki_list
