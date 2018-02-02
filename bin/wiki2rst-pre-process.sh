#!/bin/bash
usage() {
    cat << EOF

  Usage:
         $0 <rst converted from the wiki page as the input>

EOF
}

sourcerst="$1"

echo -e "Processing the converted $sourcerst...\n"

# cleanup at the beginning
sed -i '/<div class="hf-header">/,$!d' $sourcerst # remove lines before hf-header
sed -i '/:name: contents/,/rubric::/{//!d}' $sourcerst # remove toc
sed -i '/<div id="toc" class="toc">/,/:name: contents/d' $sourcerst #remove toc continue
sed -i '/rubric::/,$!d' $sourcerst # remove lines before the first rubric (the actual content)

# cleanup at the end
sed -i '/<div class="hf-footer">/,$d' $sourcerst # remove lines from hf-footer
sed -i '/.. rubric:: Archive/,$d' $sourcerst # remove lines from Archived
