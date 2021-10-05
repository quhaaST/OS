#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

int* create_array(int size) {
    int *array = malloc(sizeof(int) * size);
    return array;
}

void fill_array(int *array, int size) {
    int value = 0;
    for (int i = 0; i < size; i++) {
        *array = value;
        array++;
        value++;
    }
}

void delete_array(int *array) {
    free(array);
}

int main() {
	int size;
	printf("Enter the size of the array to create: ");
	bool sizeCorrect = false;
	while (!sizeCorrect) {
        scanf("%d", &size);
        if (size <= 0) {
            printf("Invalid size. Enter the valid one: ");
        } else {
            sizeCorrect = true;
        }
    }

	int *array = create_array(size);
    fill_array(array, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    delete_array(array);
}