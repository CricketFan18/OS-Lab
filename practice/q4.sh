n1=$1 n2=$2
n3=$3 n4=$4
n5=$5 n6=$6
n7=$7 n8=$8
result=$((n1 / n8))
for i in $(seq 2 8)
do
    a=$result
    b=$((n$i))
    if [ $((a % b)) -eq 0 ]; then
        result=$((a / b))
    elif [ $((a % b)) -ne 0 ] && [ $((b % 5)) -eq 0 ]; then
        result=$((a * b))
    elif [ $a -gt $b ]; then
        result=$((a - b))
    else
        result=$((a + b))
    fi
done
echo "Final result: $result"
