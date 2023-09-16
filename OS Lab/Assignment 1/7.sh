#!/bin/bash

read -p "Enter the file name: " filename

#to check whether the file exist
if [ ! -f "$filename" ]
then
    echo "Error: File '$filename' does not exist."
    exit 1
fi

read -p "Enter the word: " word

#to count the total number of occurrence and show the error message
total_count=$(grep -o -w "$word" "$filename" | wc -l)
if [ $total_count -gt 0 ]
then 
    echo "Total no of occurrence of $word is $total_count"
else
    echo "Error: The file $filemane doesn't contain word $word"
    exit 1
fi

line_no=1

# To count the number of occurrence of word line by line
while read -r line
do
    # echo "Line: $line"
    word_count=$(echo "$line" | grep -o -w "$word" | wc -l)
    if [ $word_count -gt 0 ]
    then
        echo "No of occurrence of $word in line $line_no is $word_count"
    fi
    ((line_no+=1))
done < "$filename"

read -p "Enter the word to replace with: " new_word

sed -i "s/$word/$new_word/g" "$filename"
echo "$word is replace with $new_word"