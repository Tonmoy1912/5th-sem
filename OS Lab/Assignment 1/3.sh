#!/bin/bash

#Write a shell script that counts the number of ordinary files (not directories) in the current working directory and its sub-directories. Repeat the count of files including the sub-directories that the current working directory has.

# no_file_dir=$(ls | wc -l)
# no_file=$(ls -l | grep "^-" | wc -l) 
no_file=$(find . -type f | wc -l)
no_dir=$(find . -type d | wc -l)
echo "No of files $no_file"
echo "No of directory $no_dir"
echo "No of files (including subdirectory and root folder) $(($no_file+$no_dir))"