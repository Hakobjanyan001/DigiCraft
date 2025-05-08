#!/bin/bash

astijan () {
	if [ $2 -eq 0 ]; then
		echo "1"
	else
		echo $(( $1 * $( astijan $1 $(( $2 -1)))))
	fi
}

astijan 4 3
