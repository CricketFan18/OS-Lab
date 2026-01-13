echo "Enter distance in Km"
read a
m=`echo $a*1000 | bc`
cm=`echo $a*100000 | bc`
echo "Metre : $m"
echo "cm : $cm"
