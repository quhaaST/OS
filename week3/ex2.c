#include <stdio.h>
#include <stdbool.h>

int read_size() {
    int size;
    bool valid = false;
    while (!valid) {
        printf("Type an array size:\n");
        scanf("%d", &size);
        if (size <= 0) { // check if the size of the array is valid
            printf("Invalid size!\n");
        } else {
            valid = true;
        }
    }
    return size;
}

void bubble_sort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int main() {
    int size;
    size = read_size();
    int arr[size];

    printf("Type an array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    bubble_sort(arr, size);

    printf("The sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}