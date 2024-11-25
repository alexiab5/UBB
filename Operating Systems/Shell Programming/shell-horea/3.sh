#!/bin/bash

if [ $# -lt 2 ]; then
	echo "You must provide at least 2 arguments"
	exit 1
fi

S=$1
shift

while [ $# -gt 0 ]; do
	if [ -f "$1" ]; then
		if grep -q "$S" "$1"; then
			echo "The file $1 contains $S"
		else
			echo "The file $1 DOES NOT contain $S"
		fi
	elif [ -d "$1" ]; then
		a=`find $1 -type f -name $S`
		if [ -n "$a" ]; then
			echo "The directory $1 contains the file $S"
		else
			echo "The directory $1 DOES NOT contain the file $S"
		fi
	fi
	shift	
done
