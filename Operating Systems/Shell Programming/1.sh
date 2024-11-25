#/bin/bash

if [ $# -eq 0 ]; then
	echo "no"
	exit 1
fi

while true; do
	for u in $@; do
		if grep -E -q "^$u:" /etc/passwd ; then
		#if id $0 > /dev/null 2> /dev/null; then	
		count=`s -u $0 | awk 'NR > 1' | wc -l`
			echo "$0 - $count"
		fi
	done
	sleep 1
done


