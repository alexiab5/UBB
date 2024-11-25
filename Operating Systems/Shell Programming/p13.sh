#!/bin/bash

if [ $# -eq 0 ]; then
	echo "You must provide at least ione argument"
	exit 1
fi

for link in `find "$1" -type l`; do
	echo $link
	if [ ! -e "$link" ]; then
		echo "The link is not valid"
	else echo valid
	fi
done
