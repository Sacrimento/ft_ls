i=40
while (( $i < 49 ))
do
	printf "\033[";
	printf $i;
	printf "m";
	printf "YGARROT LE DEUS\033[0m\n";
	((i++))
done;
