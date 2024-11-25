#!/bin/bash

if [ $# -lt 1 ]; then
	echo "You must provide at least one username"
	exit 1
fi

while [ $# -gt 0 ]; do
	user=$1
	if grep -q -E "^$user:" "/etc/passwd"; then
		proc=`ps -ef | awk '{print $1}' | grep -E "^$user$" | uniq -c`
		if [ -n "$proc" ]; then
			echo $proc
		else
			echo "0 $user"
		fi
	else
		echo invalid user
	fi
	shift
	sleep 1
done
