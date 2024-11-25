#!/bin/bash

if [ $# -eq 0 ]; then
	echo incorect
	echo utilizare: ./6.sh file1 file2...
	exit 1
fi

word=""
read -p "Enter a word: " word
while [ "$word" != "stop" ]; do
	for file in $@; do
		if [ -f $file ]; then
			if [ `echo $file | grep -E "\.txt"` ]; then
				echo "File: $file"
				echo "Nr lines: "
				cat $file | wc -l
				awk '{print "Line " NR " : " NF " words"}' $file
				p=`mktemp`
				i=`mktemp`
				cat -n $file | awk 'NF % 2 == 1 && NF != 1 {printf("%s\n",$0)}' >> $p
				#cat $p > $file
				cat -n $file | awk 'NF % 2 == 0 || NF == 1 {printf("%s\n",$0)}' >> $i
				#cat $i >> $file
				rm $i
				rm $p
				
			else 
				echo "$file is not a text file"				
			fi
		else
			echo "$file is not a text file"
		fi
	done
	read -p "Enter a word: " word
done
