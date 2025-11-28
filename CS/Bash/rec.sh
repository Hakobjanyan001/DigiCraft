#!/bin/bash
factorial(){
if [ $1 -lt 0 ];then
echo "Number is negative"
exit 1
fi
if [ $1 -le 1 ];then
echo 1
else
prev=$(factorial $(($1 - 1)))
echo "$(($1 * $prev))"
fi
}

factorial 5
