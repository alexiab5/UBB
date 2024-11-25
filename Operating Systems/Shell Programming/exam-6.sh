#!/bin/bash

if [ -f $1 ]; then
	if ls -l $1 | grep -E -q "^.[rwx]{3}"; then
		echo $1 exists and the user has permissions set on it
	else
		echo The user does not have any permissions on the file $1
	fi
else 
	echo The file $1 does not exist
fi
