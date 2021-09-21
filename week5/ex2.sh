#!/bin/sh

FILE_NAME="ex2.txt"
LOCKER="${file_name}.lock"

# check for a file presence
if [ ! -f $FILE_NAME ]
then
	echo 0 > $FILE_NAME
fi

# make the process run till interupted
while true
do
	# check if file is not modifying now
	if ln $FILE_NAME $LOCKER
	then
		VAL=$( tail -n 1 $FILE_NAME ) # read last value
		echo $((VAL + 1)) >> $FILE_NAME # update a value and append a file
		rm $LOCKER
	fi
done


# critical region here is represented in lines 18, 19.
# on these lines of code we want to have an access to a file's last line, but we don't know if the line is unchangeable during the run of current process.


