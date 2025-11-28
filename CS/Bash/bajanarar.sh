#!/bin/bash

bajanarar () {
	if (( $1 % $2 == 0 )); then
		echo "$2"
	else
		echo "$( bajanarar $2 $(( $1 % $2 )))"
	fi
}

bajanarar 64 8
