#!/bin/bash

if [ $# -lt 1 ]; then
	echo "Not enough arguments"
	exit 1
fi

for f in $@; do
	if [ -f $f ]; then
		du -b $f
	fi

done | sort -n
