#!/bin/bash

# Extend the shell script written in (6) to perform the following task: User is asked to enter two
# different patterns or words. The first pattern will have to be matched with the contents of the
# file and replaced by the second pattern if a match occurs. If the first pattern does not occur in
# the file, an appropriate error message will be displayed

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