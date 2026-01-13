echo "Enter a 3-digit number"
read n
if [ $((n % 10)) = $((n / 100)) ];
then echo "It is palindrome"
else echo "It is not palindrome"
fi
