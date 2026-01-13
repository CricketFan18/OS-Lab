#!/bin/bash
echo "Enter 10 numbers"
for i in $(seq 0 9)
do
        read a[$i]
done
echo  ${a[@]}
for i in $(seq 0 9)
do
	isPrime=1
	for j in $(seq 2 $((a[$i] / 2 )) )
	do
	       	if [ $(( a[$i] % j )) -eq 0 ]
	        then
        	        isPrime=0
			break;
    		fi
	done

	if [ $isPrime -eq 1 ]
	then	
		echo "${a[$i]} is Prime"
	fi
done
