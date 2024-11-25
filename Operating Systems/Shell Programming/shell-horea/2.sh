#!/bin/bash

#home_dirs=`grep -E ":/home/" /etc/passwd | sed -E 's/(.*)(\/home\/.*):(.*)$/\2/'`

home_dirs=`awk -F: '$6 ~ /\/home/ {print $6}' /etc/passwd`

for d in $home_dirs; do
	if ls -ld $d | grep -E -q -v "^.{4}-{6}"; then
		echo $d
	fi		
done
