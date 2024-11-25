#!/bin/bash

if [ $# -lt 1 ]; then
	echo "Insufficient args."
	exit 1
fi

if [ ! -d "$1" ]; then
	echo "Parameter is not a directory"
	exit 1
fi

lines=0

for f in $(ls "$1" | grep -E "\.c$"); do
	if test -f "$1/$f"; then
		nr=`grep -E -c -v "^[ \t]*$" "$1/$f"`
		echo "$f: $nr"
		lines=`expr $lines + $nr`

	fi
done
echo "Total number of lines: $lines"


