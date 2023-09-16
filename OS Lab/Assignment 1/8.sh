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

    for file in "."/*
    do
        size=$(du -b "$file")
        for i in $size
        do
            # echo $i
            if [ "$i" -ge "$min_size" ]
            then
                echo "FileName: $file   |  Size: $i bytes"
                echo "FileName: $file   |  Size: $i bytes" >> $filename
            fi
            break
        done
    done

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