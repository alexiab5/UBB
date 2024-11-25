#!/bin/bash

if [ $# -lt 1 ]; then
	echo "You must provide at least 1 argument"
	exit 1
fi

if [ ! -d $1 ]; then
	echo "$1 is not a valid directory"
	exit 1
fi

prev_state=`find "$1" -printf '%P\n'`
folder="$1"
previous_state=$(find "$folder" -printf '%P\n')
while true; do
    current_state=$(find "$folder" -printf '%P\n')
            diff=$(diff <(echo "$previous_state") <(echo "$current_state"))
            if [ -n "$diff" ]; then
	            echo "Change detected:"
		    echo "$diff"
     	            	previous_state="$current_state"
	    fi
            sleep 1  # Adjust the interval as needed
done
											  


