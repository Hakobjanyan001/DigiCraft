#1
# directory() {
# url=$1
# for i in "$url"/*; do
# if [ -f "$i" ];then
# echo "$i"
# elif [ -d $i ];then
# 	directory $i
# fi	
# done
# }
# if [ -z "$1" ];then
# exit 1
# fi
# directory $1	

#2
#tr -cs '[:alpha:]' '\n' < text.txt | sort | uniq -c | sort -nr

#3
#while true; do
#read -p "input numbers and operator = " exercise
#	if [ "$exercise" = "quit" ];then
#echo "Exit"
#break
#fi
#result=$(echo "$exercise" | bc)
#echo "Result = $result"
#done

#4
#factorial(){
#if [ $1 -lt 0 ];then
#echo "Number is negative"
#exit 1
#fi
#if [ $1 -le 1 ];then
#echo 1
#else
#prev=$(factorial $(($1 - 1)))
#echo "$(($1 * $prev))"
#fi
#}
#
#factorial 5

#5
#while true; do
#	echo "=====Menu====="
#	echo "1) The Date"
#	echo "2) Listing files"
#	echo "3)Exit"
#	read -p "Press (1-3) = " num
#	case $num in
#		1) echo "Date and time : $(date)";;	
#		2) echo -e "Listing filesi \n $(ls)";;
#		3) echo "Exit"
#			break ;;
#		*) echo "Press 1,2 or 3"
#	esac
#done 

#6
#read -p "File name = " file
#if [ ! -f "$file" ];then
#echo "file not found"
#	exit 1
#fi
#read -p "text name = " text
#read -p "text new name = " newtext
#while IFS= read -r line;do
#swap=$( echo "$line" | sed "s/$text/$newtext/g" ) 
#	echo "$swap"
#done < $file	

#7
#read -p "Input File Name = " file
#if [ ! -f "$file" ];then
#echo "File Not Found"
#exit 1
#fi
#read -p "Input word = " word
#while IFS= read -r line;do
#if echo "$line" | grep -q "$word" ;then
#echo $line 
#fi
#done < $file

#8
#read -p "Input Directory Name = " directory
#if [ ! -d "$directory" ];then
#echo "Directory Not Found"
#exit 1
#fi
#read -p "Input File Extension = " extension
#find $directory -name "*$extension"

#9
#file="text.txt"
#case "$1" in
#1) 
#text="${@:2}"
#echo "$text" >> "$file"
#echo "$text added"	
#;;
#2) 
#if [ ! -s "text.txt" ];then
#echo "List empty"
#else
#echo "List"
#num=1
#while IFS= read -r text ;do
#echo "$num $text"
#num=$((num + 1))
#done < $file
#fi	
#;;
#3) 
#num=$2
#if ! [[ "$num" =~ ^[0-9]+$ ]];then
#echo "press correct number"
#elif [ "$num" -le 0 ] || [ "$num" -gt "$(wc -l < "$file")" ];then
#echo "the text under this number does not exist"
#else
#	sed -i "${num}d" "$file"
#	echo "number deleted"
#fi
#	;;
#*)
#	echo "add = 1 'TEXT'"
#	echo "list = 2"
#	echo "delete = 3 'TEXT NUMBER'"
#;;
#esac

#10
#if [ -z "$1" ]; then
#  echo "use file = text.txt"
#  exit 1
#fi
#
#total=0
#score=0
#exec 3<$1 
#while IFS="," read -r question answer <&3; do
# if [ -z "$question" ] || [ -z "$answer" ];then
#	 continue
# fi
#       	echo "$question"
#read -p "input answer = " user
#
#  if [ "$answer" = "$user" ]; then
#    echo "True"
#    score=$((score + 1))
#  else
#    echo "False"
#  fi
#
#  total=$((total + 1))
#done 
#
#echo "Result: $score/$total"

#11
#fibonachi(){
#if [ $1 -eq 2 ] || [ $1 -eq 1 ];then
#echo 1
#else
#sum1=$(fibonachi $(($1 - 1)))
#sum2=$(fibonachi $(($1 - 2)))
#echo $(($sum1 + $sum2))
#fi
#}
#fibonachi 8

#12
#read -p "Input Source Folder : " sour
#if [ ! -d "$sour" ];then
#echo "Source Folder False"
#exit 1
#fi
#
#read -p "Input Destination Folder : " dest
#if [ ! -d "$dest" ];then
#echo "Destination Folder False"
#exit 2
#fi
#
#read -p "Copy? y/n : " confirm
#if [ "$confirm" == "y" ];then
#cp -r "$sour"/* "$dest"
#echo "Copy True"
#else 
#	echo "Copy False"
#fi

#13
#while true; do
#read -p "Input email : " email
#if [[ $email =~ ^[a-zA-Z0-9]+@[a-zA-Z]+\.[a-zA-Z]{2,3}$ ]] ;then
#	echo "Email True $email"
#	break
#else
#	echo "email False"
#fi
#done

#14
#if [ $# -ne 2 ];then
#echo "please use 'username' and 'login/logout'"
#exit 1
#fi
#
#username=$1
#action=$2
#logfile="log.txt"
#
#if [[ "$action" != "login" && "$action" != "logout" ]];then
#echo "Action error"
#exit 2
#fi
#
#timestamp=$(date)
#
#echo "$timestamp - Username : $username - Action : $action" >> $logfile
#echo "added : $username $action"

#15
#prime(){
#	read -p "Input number : " num
#if (( $num % 2 == 0)); then
#echo "The number is even"
#fi
#num2=$(( $num / 2 ))
#while [ $num2 -ge 2 ];do
#	if (( $num % $num2 == 0 )) ;then
#	echo "number is not prime"
#	exit 1
#	fi
#	(( num2-- ))
#done
#echo "$num : Number is prime "
#}
#prime $number














