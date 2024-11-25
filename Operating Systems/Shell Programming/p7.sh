#!/bin/bash

if [ ! $# -eq 1 ]; then
	echo "Invalid number of arguments"
	exit 1
fi

if [ ! -d $1 ]; then
	echo "$1 is not a directory"
	exit 1
fi

sum=0

for a in `ls $1`; do
	if [ -f "$1/$a" ]; then
		nr_bytes=`du -b "$1/$a" | awk '{print $1}'`
		sum=`expr $sum + $nr_bytes`
	fi
done

echo "The total sum of the sizes of all regular files from folder $1 is: $sum"
