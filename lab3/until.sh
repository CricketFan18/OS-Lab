i=1
until [ $i -gt 10 ]
do
    echo $i
    i=`echo $i + 1 | bc `
done
