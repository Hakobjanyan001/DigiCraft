#!/bin/bash

parz () {
	read -p "Write your number: " number
	if (( $number % 2 == 0 )); then
		echo "your number is nor peime"
		return 1
	fi
	kes=$(( $number / 2 ))
	while [ $kes -ge 2 ]; do
		if (( $number % $kes == 0 )); then
		echo "your number is not prime"
		return 2
		fi
		((kes--))
	done
	echo "your number is prume: $number"
}

parz "$number"
