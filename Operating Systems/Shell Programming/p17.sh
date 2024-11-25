#!/bin/bash

if [ $# -lt 1 ]; then
	echo "You must provide at least an argument"
	exit 1
fi

if [ ! -d $1 ]; then
	echo "$1 is not a directory"
	exit 1
fi

c_files=`ls "$1" | grep -E "\.c$"`
for f in $c_files; do
	echo $f
	rm $f
done

ls "$1" | grep -E "\.txt$" | sort
