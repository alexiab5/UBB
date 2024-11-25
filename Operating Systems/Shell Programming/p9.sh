#!/bin/bash

if [ $# -eq 0 ]; then
	echo "You must provide at least 2 arguments"
	exit 1
fi

if [ `expr $# % 2` -eq 1 ]; then
       echo "You must provide an even number of arguments"
       exit 1 
fi

while [ $# -gt 0 ]; do
	if [ -f $1 ]; then
		words=`cat "$1" | grep -E -o "\<$2\>" | wc -l`
		if [ $words -ge 3 ]; then
			echo "The word '$2' appears at least 3 times in $1"
		else
			echo "The word '$2' does not appear at least 3 times in $1"
		fi
	else
		echo "$1 is not a file"
	fi
	shift 2
done
