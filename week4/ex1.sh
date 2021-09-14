#!/bin/sh
for i in 1 2 3 4 5 6 7 8 9 10
do
	echo $i iteration:
	./ex1
done

# Here we make a loop of 10 iterations, where at each iteration we execute a compiled ./ex1 C file.
