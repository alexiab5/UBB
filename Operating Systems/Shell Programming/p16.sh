#!/bin/bash

if [ $# -lt 1 ]; then
	echo "You must provide at least one argument"
	exit 1
fi

while true; do
	processes=`ps -ef | awk '{print $2 " " $8}'`
	for p in $@; do
		PIDs=`echo $processes | grep -E " \<$p" | awk '{print $2}'`
		if [ -n "$PIDs" ]; then
			echo "Killing $PIDs"
			kill -9 $PIDs
		fi
	done
	sleep 3
done
