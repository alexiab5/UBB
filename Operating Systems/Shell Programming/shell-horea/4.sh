#!/bin/bash

if [ $# -lt 3 ]; then
	echo "You must provide at least a triplet"
	exit 1
fi

if [ ! `expr $# % 3` -eq 0 ]; then
	echo "Number of arguments not divisible by 3"
	exit 1
fi

while [ $# -gt 0 ]; do
	D=$1
	N=$2
	M=$3
	if [ -d "$1" ]; then
		if echo $N | grep -E -q "^[0-9]+$" && echo $M | grep -E -q "^[0-9]+$"; then
			if [ $N -lt $M ]; then
				nr_files=$(find $D -type f | wc -l)
				if [ $nr_files -ge $N -a $nr_files -le $M ]; then
					echo ok
				else 
					echo no
				fi
			else
				echo "$N >= $M"
			fi
		else
			echo "either $N or $M is not a number"
		fi
	else
		echo "$1 is not a folder"
	fi
	shift 3
done
