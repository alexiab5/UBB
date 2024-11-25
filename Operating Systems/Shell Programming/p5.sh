#!/bin/bash

file_name=""
while [ ! -f "$file_name" ]; do
	read -p "Please enter the name of a file: " file_name
done
