#!/bin/sh
if [ ! -f $2 ]; then
	echo " Tap tin $2 khong ton tai." > $3
elif 
	grep -q $1 $2; then
		echo "Trong tap tin $2 co chuoi $1." > $3
	else 
		echo "Trong tap tin $2 khong co chuoi $1." > $3
fi
exit 0
