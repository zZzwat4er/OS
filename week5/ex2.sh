if [ ! -e out2.txt ]; then
	echo 1 > out2.txt
fi

#because .we traying to create .lock file that cannot be created twice 
#there is no race condition 
#and our second script well stak untill it create .lock file
#also we can get deadlock if we won't delete .lock file	

while ! ln ./out2.txt ./out2.txt.lock
do
	sleep 0.2
done

#this line use "rm ./out2.txt.lock" comand when our script exits 
trap "rm ./out2.txt.lock" EXIT

for i in {1..10}
do
	x=$(cat out2.txt | tail -n1)
	x=$(expr $x + 1)
	echo $x >> out2.txt
done