echo "Enter a string"
read str
rev=`echo $str | rev`
if [ $str = $rev ]
then
	echo "This is palindromne"
else
	echo "This is not a palindrome"
fi
