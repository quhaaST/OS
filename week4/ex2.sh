#!/bin/sh

./ex2 &

for i in 1 2 3 4 5
do
	echo After the $i iteration of loop:
	pstree | grep ex2
	sleep 5
done
