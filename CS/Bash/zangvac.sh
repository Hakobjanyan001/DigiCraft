#!/bin/bash

#if [ $1 -gt $2 ]; then
#	res=$(( $1 - $2 ))
#	echo "$res"
#elif [ $1 -lt $2 ]; then
#	res=$(( $2 - $1 ))
#	echo $res
#else
#	echo "$1 = $2"
#fi

avto=("yeraz" "lexus" "toyota")
echo "${avto[@]}"
avto+=("mers")
echo "${avto[3]}"
unset avto[0]
avto+="bmw"
echo "${avto[0]}"
echo "${#avto[2]}"
echo "${#avto[@]}"
echo "${!avto[@]}"


#declare -A mayraqaxaq
#mayraqaxaq[Hayastan]="Yerevan"
#mayraqaxaq[Vrastan]="Tbilisi"
#mayraqaxaq[Iran]="Tehran"


#for qaxaq in "${!mayraqaxaq[@]}"; do
#       echo "${mayraqaxaq[$qaxaq]}"
#done       
