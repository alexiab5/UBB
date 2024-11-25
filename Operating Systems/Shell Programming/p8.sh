#!/bin/bash

fname=""
while [ "$fname" != "stop" ]; do
	read -p "Enter a file name or stop: " fname
	if [ -f $fname ]; then
		echo "$fname is a regular file"
		if file $fname | grep -q "text"; then
			echo "$fname is a text file"
			echo "Number of words on the first line of $fname: `head -1 $fname | awk '{print NF}'`"
		else
			echo "$fname is not a text file"
		fi
	fi
done
