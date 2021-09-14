#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>


int main() {
	int BUFF_SIZE = 256;
    while (1) {
		printf("> ");
        char command[256];
		scanf("%s", command);
		system(command);
	}
}
