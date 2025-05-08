#!/bin/bash
fibonachi(){
if [ $1 -eq 2 ] || [ $1 -eq 1 ];then
echo 1
else
sum1=$(fibonachi $(($1 - 1)))
sum2=$(fibonachi $(($1 - 2)))
echo $(($sum1 + $sum2))
fi
}
fibonachi 5
