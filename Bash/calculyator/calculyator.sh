#!/bin/bash

History="file.txt"
read -p "For calculyator write cal 
for history write history
for exit write exit 
" aa
if [ "$aa" == "cal" ]; then
	read -p "write your var1 " var1
	read -p "write your operator " oper
	read -p "write your var2 " var2
	
	add(){
		echo $(($var1 + $var2))
	}
	
	remove(){
		echo $(($var1 - $var2))
	}
	
	division(){
		if [ "$var2" -eq 0 ]; then
			echo "var2 can not be 0" 
		else
		echo $(($var1 / $var2))
		fi
	}
	
	multiplication(){
		echo $(($var1 * $var2))
	}
	
	case $oper in 
		+)result=$(add);;
		-)result=$(remove);;
		/)result=$(division);;
		\*)result=$(multiplication);;
		*)echo "Invalid case";;
	esac
	
	echo "Result: $result"
	
	echo $var1 $oper $var2  = $result >> "$History" 
elif [ "$aa" == "history" ]; then 
	if [ -f "$History" ] && [ -s "$History" ]; then
		while read line; do
			echo "$line"
		done < "$History"
	else 
		echo "file invalid"
	fi
else
	echo "invalid input"
fi
