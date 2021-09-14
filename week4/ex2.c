#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	int n = 5;
	for (int i = 0; i < n; i++) {
		fork();	
		sleep(5);
	}

	return 0;
}

/*
	We are calling a fork() function 5 times, so that the initial first process will create 5 more processes.
	Each new process created by this function will continue to create other processes.
	In the end we will have a situation, with 32 running processes, which is following to the formulae № of processes = 2^(№ loop iterations).
	Therefore, if we make a program run 3 iterations, then we will have 2^3 = 8 running processes (can be seen during ex2.sh runtime).
	If we make a program run n iteration, then we will have 2^n running processes.
*/
