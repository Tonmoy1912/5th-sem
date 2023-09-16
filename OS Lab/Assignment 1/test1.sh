#!/bin/bash

filename="test1.txt"

while read -r line
do
    # echo "Line: $line"
    # word_count=$(echo "$line" | grep -o -w "$word" | wc -l)
    word_count=0
    for i in $line
    do
        echo $i
        
        ((word_count+=1))
    done
    if [ $word_count -gt 0 ]
    then
        echo "No of occurrence of $word in line $line_no is $word_count"
    fi
    ((line_no+=1))
done < "$filename"
