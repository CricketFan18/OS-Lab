echo "Enter 10 numbers"
for i in $(seq 0 9)
do
        read a[$i]
done
echo "Original array: ${a[@]}"

echo -n "Reversed array: "
for ((i=9; i>=0; i--))
do
    echo -n "${a[$i]} "
done
echo
