#!/bin/bash
usage() {
    cat << EOF

  Usage:
         $0 <wiki link as the input> <rst converted from the wiki page as the output>

EOF
}

wikiurl="$1"
sourcerst="$2"
sourcehtml="$(sed -e 's|rst|html|g'<<<$sourcerst)"
sourcerstorig="$(sed -e 's|rst|orig|g'<<<$sourcerst)"

echo -e "Saving $wikiurl to $sourcehtml...\n"
curl $wikiurl > $sourcehtml

echo -e "Converting $sourcehtml to $sourcerst...\n"
cp $sourcerst $sourcerstorig
pandoc -s -t rst $sourcehtml -o $sourcerst

echo -e "Removing the temporary $sourcehtml...\n"
rm -rf $sourcehtml

echo -e "Processing the converted $sourcerst...\n"

# cleanup at the beginning
sed -i '/<div class="hf-header">/,$!d' $sourcerst # remove lines before hf-header
sed -i '/:name: contents/,/rubric::/{//!d}' $sourcerst # remove toc
sed -i '/<div id="toc" class="toc">/,/:name: contents/d' $sourcerst #remove toc continue
sed -i '/rubric::/,$!d' $sourcerst # remove lines before the first rubric (the actual content)

# cleanup at the end
sed -i '/<div class="hf-footer">/,$d' $sourcerst # remove lines from hf-footer
sed -i '/.. rubric:: Archive/,$d' $sourcerst # remove lines from Archived

# insert the original file which has the wiki links as the comment
cat $sourcerstorig $sourcerst >out && mv out $sourcerst
rm -rf $sourcerstorig
