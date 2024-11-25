#!/bin/bash

if [ $# -eq 0 ]; then
	echo "You must provide at least an argument"
	exit 1
fi

for f in $@; do
	if [ -f $f ]; then
		du -b $f
	fi
done | sort -n -r -k1
