#!/bin/bash

# Write a shell program to duplicate the UNIX rm command with the following features:
# a. Instead of deleting the files, it will move them to a my-deleted-files directory. If the file already exists in the my-deleted-files directory, then the existing file (in the my-deleted-files) will have the version number zero (0) appended to it and the newly deleted file will have version number one (1) appended to it. Go on incrementing the version nos., if required.
# b. The command will have a switch -c that will clear the entire my-deleted-files directory after asking for confirmation. 




deleted_dir="my-deleted-files"


# Function to move files to the my-deleted-files directory
move_to_deleted() {
    file="$1"
    # base_name
    # extension
    version=0

    # Extract the base name and extension of the file
    base_name="${file%.*}"
    extension="${file##*.}"

    if [ -e "$deleted_dir/$base_name.$extension" ]
    then
        mv "$deleted_dir/$file" "$deleted_dir/$base_name$version.$extension"
    fi

    # Check if the file already exists in the my-deleted-files directory
    while [ -e "$deleted_dir/$base_name$version.$extension" ]
    do
        ((version++))
    done

    if [ $version -eq 0 ]
    then
        # Move  the file without any version number
        mv "$file" "$deleted_dir/$file"
    else
        # Move the file to the my-deleted-files directory with the version number
        mv "$file" "$deleted_dir/$base_name$version.$extension"
    fi

    
}

# Function to clear the entire my-deleted-files directory
clear_deleted_directory() {
    read -p "Are you sure you want to clear the my-deleted-files directory? (y/n): " confirm
    if [ "$confirm" = "y" ]
    then
        rm -r "$deleted_dir"/*
        echo "my-deleted-files directory cleared."
    else
        echo "Operation canceled."
    fi
}

# Check if the my-deleted-files directory exists, and create it if not
if [ ! -d "$deleted_dir" ]
then
    mkdir "$deleted_dir"
fi

# args_no=$#

if  [ $1 == "-c" ]
then 

    clear_deleted_directory

else
    # Loop through the remaining arguments (files to be deleted)
    for file in "$@"
    do
        if [ -e "$file" ]
        then
            move_to_deleted "$file"
            echo "Moved '$file' to $deleted_dir."
        else
            echo "Error: '$file' does not exist."
        fi
    done
fi