#include "stdio.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a, b;
    printf("Please, type here 2 numbers to swap their values: ");
    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("Here is their values after swapping: %d %d", a, b);

    return 0;
}