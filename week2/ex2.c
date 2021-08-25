#include "stdio.h"
#include "string.h"

int main() {
    char input[255], reversed[255];
    int len;
    printf("Please, enter the string to reverse: ");
    scanf("%s", input);
    len = strlen(input); // get len of the given string
    reversed[len] = input[len]; // make sure that the reversed string has the null symbol at the end
    for (int i = 0; i < len; i++) {
        reversed[len - i - 1] = input[i];
    }
    printf("Here is the reversed string: %s\n", reversed);

    return 0;
}

