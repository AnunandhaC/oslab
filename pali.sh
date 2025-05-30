#!/bin/bash
start=$1
end=$2
for((i=start;i<=end;i++)); do
	reversed=$(echo $i | rev)
	if [ "$i" -eq "$reversed" ]; then
		echo "$i"
	fi
done
