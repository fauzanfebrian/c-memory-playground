#include <stdio.h>
#include "math_utils.h"

#define B_MACROS 10

int main() {
    printf("This program was compiled on %s at %s.\n", __DATE__, __TIME__);

    int a = 12;
    int max = findMax(a, B_MACROS);
    printf("Max: %d\n", max);
}