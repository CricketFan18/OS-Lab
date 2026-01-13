a=$1
b=$2
c=`echo $a + $b | bc`
echo "result=$c"
