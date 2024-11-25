#!/bin/bash

for f in `awk -F: '{print $6}' /etc/passwd`; do
	if ! ls -ld $f 2> /dev/null | grep -E -q "^.{4}-{6}"; then
		user=$(awk -F: -v x=$f ' $6==x {print $5}' /etc/passwd | awk -F"-" '{print $1}')
		echo $user - $f
	fi
done
