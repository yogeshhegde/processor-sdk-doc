#!/bin/bash
usage() {
    cat << EOF

  Usage:
         $0 <wiki link> <rst output>

EOF
}

wikiurl="$1"
sourcerst="$2"
sourcehtml="$(sed -e 's|rst|html|g'<<<$sourcerst)"

echo -e "Saving $wikiurl to $sourcehtml...\n"
curl $wikiurl > $sourcehtml

echo -e "Converting $sourcehtml to $sourcerst...\n"
pandoc -s -t rst $sourcehtml -o $sourcerst

echo -e "Removing the temporary $sourcehtml...\n"
rm -rf $sourcehtml
