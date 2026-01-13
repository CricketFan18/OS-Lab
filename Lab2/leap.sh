echo "Enter year"
read y
if [ `echo $y % 4 | bc` -eq 0 ]
then
	if [ `echo $y % 400 | bc` -eq 0  -o  `echo $y % 100 | bc` -ne 0 ]
	then
		 echo "It is a leap year"
	else
       		 echo "It is not a leap year"
	fi
else
	echo "It is not a leap year"
fi 
