#include <stdio.h>
#include <malloc.h>
#include <memory.h>

void *my_realloc(void *ptr, size_t newSize) {
    void *newPtr;
    newPtr = malloc(newSize);
    size_t initialSize = malloc_usable_size(ptr);
    if (ptr != NULL) {
        if (initialSize < newSize) {
            memcpy(newPtr, ptr, initialSize);
        } else {
            memcpy(newPtr, ptr, newSize);
        }
        free(ptr);
    }

    return newPtr;
}

int main() {
    int arraySize = 5, newSize = 10;
    int *array = malloc( arraySize * sizeof(int));
    for (int i = 0; i < arraySize; i++) {
        *(array + i) = i;
    }

    for (int i = 0; i < arraySize; i++) {
        printf("%d ", *(array + i));
    }

    printf("\n");

    array = my_realloc(array, sizeof (int) * newSize);
    for (int i = 0; i < newSize; i++) {
        printf("%d ", *(array + i));
    }
}