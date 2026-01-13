echo "Enter 10 numbers"
for i in $(seq 0 9)
do
	read a[$i]
done
echo  ${a[@]}
sumodd=0
sumeven=0
for i in $(seq 0 9)
do
        if [ $(( a[$i] % 2 )) -eq 0 ]
	then
		sumeven=$(( sumeven + a[$i] ))
		echo "Even ${a[$i]}"
	else
		sumodd=$(( sumodd + a[$i] ))
		echo "Odd ${a[$i]}"
	fi
done
echo "Even Sum = $sumeven"
echo "Odd Sum = $sumodd"
