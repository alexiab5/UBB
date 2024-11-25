#!/bin/bash

if [ $# -lt 1 ]; then
	echo "You must provide at least one argument"
	exit 1
fi

if [ ! -d $1 ]; then
	echo "$1 is not a folder"
	exit 1
fi

find . -type f | awk -F/ '{print $NF}' | sort | uniq -c
