echo "Enter 10 numbers"
for i in $(seq 0 9) 
do
        read arr[$i]
done
sorted_arr=( $arr | sort -n))

echo "Sorted Array: ${sorted_arr[@]}"

