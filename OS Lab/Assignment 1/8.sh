#!/bin/bash


filename="logfile.txt"

if [ ! -f $filename ]
then
    touch $filename
fi

greeting(){
    cur_time=$(date +"%H")
    time="morning"
    if [ $cur_time -gt 3 ]
    then
        time="evening"
    fi
    echo
    echo "Hello $USER good $time"
    echo "Hello $USER good $time" >> $filename
    echo
}

show_disk_usage(){
    disk_usage=$(df -h)

    echo
    echo "Disk Usage Information:"
    echo "Disk Usage Information:" >> $filename
    echo "-----------------------"
    echo "-----------------------" >> $filename
    echo "$disk_usage"
    echo "$disk_usage" >> $filename
    echo
}

list_files(){

    read -p "Enter the minimum file size in bytes: " min_size

    echo
    echo "List of files greater than or equal to ${min_size} bytes:"
    echo "List of files greater than or equal to ${min_size} bytes:" >> $filename
    echo "-----------------------------------------"
    echo "-----------------------------------------" >> $filename
    echo "File Name      | Size (Bytes)"
    echo "File Name      | Size (Bytes)" >> $filename
    echo "-----------------------------------------"
    echo "-----------------------------------------" >> $filename

    find . -type f -size +${min_size}c -exec du -b {} \; | awk -v min_size="${min_size}" '$1 >= min_size {printf "%-15s | %s\n", $2, $1}'
    find . -type f -size +${min_size}c -exec du -b {} \; | awk -v min_size="${min_size}" '$1 >= min_size {printf "%-15s | %s\n", $2, $1}' >> $filename

    echo "-----------------------------------------"
    echo "-----------------------------------------" >> $filename
    echo
}

show_log_file(){
    echo 
    echo "The content of $filename"
    echo
    cat $filename
    echo
}

while true
do
    echo "1. Display Greeting"
    echo "2. List Large files"
    echo "3. Disk usage"
    echo "4. View Log File"
    echo "5. Exit"
    read -p "Enter the choice no: " c

    case $c in 

        1 )
            echo "$USER%Display Greeting%" >> $filename
            greeting ;;
        2 )
            echo "$USER%List Large files%" >> $filename
            list_files ;;
        3 )
            echo "$USER%Disk usage%" >> $filename
            show_disk_usage ;;
        4 )
            echo "$USER%View Log File%" >> $filename
            show_log_file;;
        5 )
            echo "$USER%Exit%" >> $filename
            echo 
            echo "Exiting..."
            echo
            break  ;;
        * )
            echo "Error: You enter a wrong key"
            break;;

    esac


done 