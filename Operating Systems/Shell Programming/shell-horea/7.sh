#!/bin/bash

NR=`cat 2.txt | wc -l`
i=1;
#while [ $i -le $NR ]; do
#	line=$(sed -n ''$i'p' 2.txt)
#	echo $line
#3	i=$(($i + 1))
#done
for((i=1;i<=$NR;i++))
do
	line=$(sed -n ''$i'p' 2.txt)
	echo $line
done
