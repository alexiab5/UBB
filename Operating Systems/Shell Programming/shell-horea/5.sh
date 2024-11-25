#!/bin/bash

if [ ! $# -eq 1 ]; then
	echo "You must provide a number as an argument"
	exit 1
fi

if ! echo $1 | grep -E -q "^[0-9]+$"; then
	echo "$1 is not a number"
	exit 1
fi

files=""
total=0
while true; do
	        f=0
		        read -p "Enter a string: " f
			        if [ -f $f ]; then
					                lines=`cat $f | wc -l`
							                total=$(($total + $lines))
									                files="$files $f"
											                echo "The file has $lines lines. Total number of lines so far is $total "
													                #echo $files
															        else
																	                echo The file does not exist
																			        fi
																				        if [ $total -gt $1  ]; then
																						                cat $files | head -n $1
																								                exit 0
																										        fi
																										done
