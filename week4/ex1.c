#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	pid_t pid;
	pid = fork();
	int n = 5;
	for (int i = 0; i < n; i++) {
		if (pid == 0) { // check if it is a child process
			printf("Hello from child [%d - %d]\n", pid, i); 
		} else if (pid > 0) { // check if it is a parent process
			printf("Hello from parent [%d - %d]\n", pid, i); 
		} else {
			exit(EXIT_FAILURE);
		}	
	}
	return EXIT_SUCCESS;
}

/*
	We can see that during the work of a parent process the pid variable changes (at line 8), so it is different from 0.
	Moreover, the child process does not hit the 8th line an continues to work with the same data, which the parent process had before execution of line 8. So that pid variable will still have 0 value (initial value).
	Since we are running the code N = 5 times, then we will see 5 messages from parent process and 5 messages from a child process.
	Overall, there will be 5 * 2 * 10 = 100 messages from both child and parent after the execution of ex1.sh file.
*/
