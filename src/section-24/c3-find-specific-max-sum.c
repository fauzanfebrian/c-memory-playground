#include <stdio.h>
#include <stdlib.h>

int findSpecificValueMaxSum(int* arr, int size) {
    int* arrCount = calloc(sizeof(int), size + 1);
    int i;

    for (i = 0; i < size; i++) {
        arrCount[arr[i]] += arr[i];
    }

    int iMax = 0;
    for (i = 1; i < size + 1; i++) {
        if (arrCount[i] > arrCount[iMax]) {
            iMax = i;
        }
    }

    return iMax;
}

int main() {
    int example1[] = {2, 1, 3, 2, 4, 2, 1};  // 2 dominates (2+2+2 = 6)
    int example2[] = {2, 1, 3, 2, 4, 2, 7};  // 7 dominates (7)
    int example3[] = {1, 1, 1, 1};           // sum = 4
    int example4[] = {4, 4, 4};              // sum = 12
    int example5[] = {5, 5, 2, 2, 2};        // 5 wins with sum 10
    int example6[] = {0, 0, 0, 0};           // everything is zero, iMax stays 0
    int example7[] = {6};                    // trivial
    int example8[] = {};                     // empty, but your function still reads arrCount[0] so fun times
    int example9[] = {9, 1, 1};              // out of bounds access, undefined behavior, chaos
    int example10[] = {3, 3, 2, 2, 2};       // 3 sum = 6, 2 sum = 6, tie returns first max (3)

    printf("Example 1: %d\n", findSpecificValueMaxSum(example1, 7));
    printf("Example 2: %d\n", findSpecificValueMaxSum(example2, 7));
    printf("Example 3: %d\n", findSpecificValueMaxSum(example3, 4));
    printf("Example 4: %d\n", findSpecificValueMaxSum(example4, 3));
    printf("Example 5: %d\n", findSpecificValueMaxSum(example5, 5));
    printf("Example 6: %d\n", findSpecificValueMaxSum(example6, 4));
    printf("Example 7: %d\n", findSpecificValueMaxSum(example7, 1));
    printf("Example 8: %d\n", findSpecificValueMaxSum(example8, 0));
    printf("Example 9: %d\n", findSpecificValueMaxSum(example9, 3));
    printf("Example 10: %d\n", findSpecificValueMaxSum(example10, 5));
}
