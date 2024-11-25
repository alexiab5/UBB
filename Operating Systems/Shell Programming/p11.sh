#!/bin/bash

if [ $# -eq 0 ]; then
	echo "You must provide at least one argument"
	exit 1
fi

echo "" > output.txt

for f in $@; do
	if [ -f $f ]; then
		if file $f | grep -q "C source"; then
			grep -E "^#include" "$f" >> output.txt
		else 
			echo no
		fi
	fi
done
