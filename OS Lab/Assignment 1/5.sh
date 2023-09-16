#!/bin/bash

# Function to calculate the age
calculate_age() {
    bd_date="$1"
    current_date="$(date +'%d/%m/%Y')"
    # echo "Current data $current_date"

    bd_year="${bd_date##*/}"
    current_year="${current_date##*/}"
    # echo "Year $bd_year"
    # echo "Year $current_year"

    bd_month="${bd_date%/*}"
    current_month="${current_date%/*}"
    # echo "month $bd_month"
    # echo "month $current_month"

    bd_day="${bd_month%/*}"
    current_day="${current_month%/*}"
    # echo "day $bd_day"
    # echo "day $current_day"

    bd_month="${bd_month#*/}"
    current_month="${current_month#*/}"
    # echo "month $bd_month"
    # echo "month $current_month"

    # temp=$bd_date
    # bd_date=$bd_month
    # bd_month=$temp


    # temp=$current_day
    # current_day=$current_month
    # current_month=$temp


    age_years=$(expr $current_year - $bd_year )
    # echo "Age year $age_years"
    age_months=$(expr $current_month - $bd_month )
    age_days=$(expr $current_day - $bd_day )
    # echo "Age day $age_days"

    # Adjust for negative months or days
    if [ "$age_days" -lt 0 ]
    then
        age_days=$((age_days + 30)) 
        age_months=$((age_months - 1))
    fi

    if [ "$age_months" -lt 0 ]
    then
        age_months=$((age_months + 12))
        age_years=$((age_years - 1))
    fi

    echo "$age_years years, $age_months months, $age_days days"
}

# Function to check if two dates fall on the same day of the week
check_same_day_of_week() {
    date1=$(echo "$1" | awk -F'/' '{print $2"/"$1"/"$3}')
    date2=$(echo "$2" | awk -F'/' '{print $2"/"$1"/"$3}')

    day1="$(date -d "$date1" +'%A')"
    day2="$(date -d "$date2" +'%A')"

    if [ "$day1" == "$day2" ] 
    then
        echo "Same day of the week ($day1)"
    else
        echo "Different days of the week ($day1 and $day2)"
    fi
}



read -p "Enter the first date of birth: " birthday1
read -p "Enter the second date of birth: " birthday2



# Check if the days of the week match and calculate age
check_same_day_of_week "$birthday1" "$birthday2"
echo "Age of the first"
calculate_age "$birthday1"
echo "Age of the second"
calculate_age "$birthday2"
