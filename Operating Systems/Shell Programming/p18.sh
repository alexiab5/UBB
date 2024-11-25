#!/bin/bash

files=`find -type f`
for f in $files; do
	if [ -f $f ]; then
		permissions=`ls $f -l | awk '{print $1}'`
		if echo $permissions | grep -E -q "^-.w..w..w."; then
			echo $f $permissions
			chmod a-w "$f"	
		fi
	fi
done
