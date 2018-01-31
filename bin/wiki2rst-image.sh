#!/bin/bash
usage() {
    cat << EOF

  Usage:
         $0 <wiki link> <rst converted and processed>

EOF
}

image_dir="./source/images"

wikiurl="$1"
sourcerst="$2"

wget -r -nd -A File:* $wikiurl

for f in File:*; do
   img="`echo $f | sed s/File://`"
   echo $img
   img2="$(sed -e 's|_| |g'<<<$img)"
   echo $img2

   if grep -q "$img" $sourcerst  || grep -q "$img2" $sourcerst; then
      wget -r -nd -A $img $wikiurl
      mv $img $image_dir
      sed -i "/$img/c\.. Image:: ../images/$img" $sourcerst
      sed -i "/$img2/c\.. Image:: ../images/$img" $sourcerst
   fi
done

rm File:*
rm robots.txt*
rm 201*
