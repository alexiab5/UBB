#!/bin/bash

if [ $# -eq 0 ]; then
	echo "not enough arg"
	exit 1
fi

#touch file-reports.info
#echo "" > file-reports.info

for a in $@;do
	f=`find $PWD -type f -name $a`
	if [ ! -z "$f" ]; then
		ls -l $f | awk '{print $5 " " $9}' >> file-reports.info
	elif [ -d "$a" ]; then
		ls $a -Sl | grep -E "^-" | head -1 |  awk '{print $5 " " $9}' >> directory-reports.info
	else
		if [ -n `echo $a | grep -E "^[aeiou]" -i` ]; then
			touch $a
		else
			mkdir $a
		fi
	fi
done
