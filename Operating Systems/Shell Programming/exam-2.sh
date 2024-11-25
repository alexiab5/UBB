#!/bin/bash

#x=""

#while [ "$x" != "stop" ]; do
#	read x
#	echo Read: $x
#done

while true; do
	read X
	if [ "$X" == "stop" ]; then
		break
	fi
	if [ -f $X ]; then
		cat $X | head -3
	else
		echo $X is not a regular file
	fi
done
