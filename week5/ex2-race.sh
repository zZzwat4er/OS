#race condition manifest itself when we boot 2 or more copies of this script 
#and here critical region is out2.txt witch is opened by this script
if [ ! -e out2.txt ]; then
	echo 1 > out2.txt
fi

for i in {1..10}
do
	x=$(cat out2.txt | tail -n1)
	x=$(expr $x + 1)
	echo $x >> out2.txt
done