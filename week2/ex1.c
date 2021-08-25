#include <stdio.h>
#include "limits.h"
#include "float.h"

int main() {
    int int_num;
    float float_num;
    double double_num;
    int_num = INT_MAX;
    float_num = FLT_MAX;
    double_num = DBL_MAX;

    printf("The INT number size is %lu bytes.\n", sizeof(int));
    printf("The FLOAT number size is %lu bytes.\n", sizeof(float));
    printf("The DOUBLE number size is %lu bytes.\n", sizeof(double));

    printf("The INT number has maximum value of %d.\n", int_num) ;
    printf("The FLOAT number has maximum value of %f.\n", float_num);
    printf("The DOUBLE number has maximum value of %lf.\n", double_num);

    return 0;
}
