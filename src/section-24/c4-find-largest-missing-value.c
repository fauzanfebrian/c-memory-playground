#include <stdio.h>
#include <stdlib.h>

int findLargestMissingValue(int* arr, int size) {
    int* arrCount = calloc(sizeof(int), size + 1);
    int i;

    for (i = 0; i < size; i++) {
        arrCount[arr[i]] += 1;
    }

    int iMax = 0;
    for (i = size; i >= 0; i--) {
        if (arrCount[i] == 0) {
            free(arrCount);
            return i;
        }
    }

    free(arrCount);
    return -1;
}

int main() {
    int example1[] = {2, 1, 3, 2, 4, 2, 1};  // size=7, missing=7 (never appears)
    int example2[] = {0, 1, 2, 3, 4, 5, 6};  // perfect sequence, missing=7
    int example3[] = {7, 7, 7, 7, 7, 7, 7};  // only 7s, missing=6
    int example4[] = {0, 0, 0};              // missing=3
    int example5[] = {3, 1, 0, 2, 5};        // missing=4
    int example6[] = {0, 1, 2, 3, 4};        // missing=5
    int example7[] = {5};                    // size=1, arr[0]=5 ignored, missing=1
    int example8[] = {};                     // size=0, missing=0
    int example9[] = {9, 1, 1};              // values above size ignored, missing=3
    int example10[] = {1, 2, 4, 5};          // missing=3

    printf("Example 1: %d\n", findLargestMissingValue(example1, 7));
    printf("Example 2: %d\n", findLargestMissingValue(example2, 7));
    printf("Example 3: %d\n", findLargestMissingValue(example3, 7));
    printf("Example 4: %d\n", findLargestMissingValue(example4, 3));
    printf("Example 5: %d\n", findLargestMissingValue(example5, 5));
    printf("Example 6: %d\n", findLargestMissingValue(example6, 5));
    printf("Example 7: %d\n", findLargestMissingValue(example7, 1));
    printf("Example 8: %d\n", findLargestMissingValue(example8, 0));
    printf("Example 9: %d\n", findLargestMissingValue(example9, 3));
    printf("Example 10: %d\n", findLargestMissingValue(example10, 4));
}