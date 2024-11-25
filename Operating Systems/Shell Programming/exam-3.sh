#!/bin/bash

if [ -f emails.txt ]; then
	> emails.txt #!!!!! emptying the file
else
	touch emails.txt
fi

while [ $# -ne 0 ]; do
	if id $1 > /dev/null 2>&1; then
		echo $1 is a valid user
		email="$1@ubbcluj.ro"
		echo $email >> emails.txt
	else 
		echo $1 is not a valid user
	fi
	shift
done

echo Contents of emails.txt:
cat emails.txt
