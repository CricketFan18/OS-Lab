echo "Enter a number"
read n
rn=0
on=$n
while [ $n -ne 0 ]
do
	remainder=$((n % 10))
	rn=$((rn * 10 + remainder))
	n=$((n / 10))
done
echo "The reverse of $on is $rn"
