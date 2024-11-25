#!/bin/bash

if [ $# -eq 0 ]; then
	echo Please provide at least one argument
	exit 1
fi

sum=0

for d in $@; do
	if [ -d $d ]; then
		#N=`du -b $d | cut -f1`
		N=$(du -b $d | cut -f1)
		for size in $N; do
			echo $d - $size
			sum=$((sum + size))
			echo Total sum so far $sum
		done
	else
		echo $d is not a directory
	fi
done

echo Total sum in bytes: $sum
