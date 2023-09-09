#!/bin/bash

read -p "Enter the value:" str
# read - p "Enter string:" string

len=${#str}

for ((i = $len - 1; i >= 0; i--))
do
    reverse="$reverse${str:$i:1}"
done

echo $reverse