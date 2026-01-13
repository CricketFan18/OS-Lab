echo "the prime numbers are"
for i in $(seq 1 1000)
do
	isPrime=1
	for x in $(seq 2 $((i-1)))
	do
		if [ $(( i % x )) -eq 0 ]
		then isPrime=0
			break;
		fi
	done
	if [ $isPrime -eq 1 ]
	then echo "$i is Prime"
	fi
done

