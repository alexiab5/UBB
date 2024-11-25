#!/bin/bash

while [ $# -ne 0 ]; do
	if id $1 > /dev/null 2>&1; then
		echo $1 is a valid user	
		N=$(ps -ef | grep $1 | wc -l)
		echo Total number of processes for user $1: $N
		sleep 1
	else
		echo $1 is not a valid user
	fi
	shift
done
