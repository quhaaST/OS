#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
	size_t BUFF_SIZE = 256;
	while (1) {
		printf("> ");
		char *command;
		getline(&command, &BUFF_SIZE, stdin);
        system(command);
	}
}
