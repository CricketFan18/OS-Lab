echo "Enter a number"
read n
sum=0
while [ $n -ne 0 ]
do
	sum=$((sum + n % 10))
	n=$((n / 10))
done
echo "Sum of digits = $sum"
