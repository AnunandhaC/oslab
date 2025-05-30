#!/bin/bash
echo "filename"
read fname
echo "word"
read word
if [[ -f $fname ]]
then
	wordc=$(grep -o -i "$word" "$fname" |wc -l)
	echo "occured $wordc"
else
	echo "file not found"
fi

