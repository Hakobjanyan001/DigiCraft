#!/bin/bash

factoryal () {
if [ $1 -lt 0 ]; then
	echo "your number is negative"
	exit 1
elif [ $1 -le 1 ]; then
	echo "1"
else
	prev=$( factoryal $(( $1 - 1)))
	echo $(( $1 * $prev))
fi	
}
factoryal 5
