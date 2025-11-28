#!/bin/bash

#1-in tarberak
#a=2
#b=3

#res=$(( a ** b ))
#echo $res


astijan () {
	if [ $2 -eq 0 ]; then
		echo "1"
	else
		echo $(( $1 * $( astijan $1 $(( $2 -1)))))
	fi
}

astijan 4 3
