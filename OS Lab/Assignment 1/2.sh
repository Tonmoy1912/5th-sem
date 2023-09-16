#!/bin/bash

read -p "Enter the file name:" file

if ! [[ -f $file ]]
then 
    touch $file
    echo "$file created, write something in file and do Ctrl+d to exit"
    cat > $file
fi

# line_no=`wc --lines < $file`
line_no=$(wc -l < $file)
# line_no=$(($line_no + 1))

echo "The number of line in the file is $line_no"