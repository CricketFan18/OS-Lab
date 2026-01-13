ps -ef > op.txt
echo "Details of processes with PPID = 2 from ps -ef:"
awk '$3 == 2 {print $0}' op.txt | head -n 20
rm op.txt
ps -ux > op2.txt
echo "Details of processes with PPID = 2 from ps -ux:"
awk '$3 == 2 {print $0}' op2.txt | head -n 20
rm op2.txt
