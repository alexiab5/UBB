#!/bin/bash

users=`ps -ef | awk 'NR > 1 {print $1 "," $2}' | sort`
prev=""
sum=0
nr=0
for u in $users; do
	user_id=`echo $u | cut -d, -f1`
	pid=`echo $u | cut -d, -f2`
	if [ -z "$prev" ]; then 
		prev=$user_id
		nr=1
		sum=$(($sum + $pid))
	elif [ "$prev" = "$user_id" ]; then
		#echo $prev - $nr
		nr=$(($nr + 1))
		sum=$((sum + $pid))
	else
		avg=$(($sum / $nr))
		echo "$prev - $avg"
		prev=$user_id
		sum=$pid
		nr=1
	fi
done

avg=$(($sum / $nr))
echo "$prev - $avg"
