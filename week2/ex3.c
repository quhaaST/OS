#include "stdio.h"
#include "stdlib.h"

int main(int argc, char* argv[]) {
    int size;
    
    if (argc == 1) {
	printf("No figure size was provided.\n");
	} else {
		sscanf(argv[1], "%d", &size);

		// printing the triangle
		for (int i = 0; i < size; i++) {
		    for (int j = 0; j < 2 * size; j++) {
		        if (j + i < size || j - i > size) { // check if the space symbol or star should appear
		            printf(" ");
		        } else {
		            printf("*");
		        }
		    }
		    printf("\n");
		}
    }

    return 0;
}
