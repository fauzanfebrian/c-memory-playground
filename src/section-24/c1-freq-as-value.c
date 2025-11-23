#include <stdio.h>
#include <stdlib.h>

int freqAsValueCheck(int* arr, int size, int k) {
    int* arrCount = calloc(sizeof(int), k);

    for (size_t i = 0; i < size; i++) {
        int t = arr[i];

        if (arr[i] > k) {
            free(arrCount);
            return 0;
        }

        arrCount[arr[i]] += 1;

        if (arrCount[arr[i]] > arr[i]) {
            free(arrCount);
            return 0;
        }
    }

    free(arrCount);
    return 1;
}

int main() {
    int example1[] = {1, 2, 2, 1, 4, 3};  // valid
    int example2[] = {3, 2, 2, 1, 3, 3};  // invalid freq
    int example3[] = {1, 1, 1, 1};        // too many 1s
    int example4[] = {2, 2};              // valid, both appear twice
    int example5[] = {4, 4, 4, 4};        // valid freq but only if k >= 4
    int example6[] = {5, 1, 1};           // element > k case
    int example7[] = {};                  // empty input edge case
    int example8[] = {2, 2, 3, 3, 3};     // invalid because frequency of 3 > 3
    int example9[] = {3, 3, 3};           // valid (freq = 3 and val = 3)
    int example10[] = {1};                // valid by default

    printf("Example 1: %d\n", freqAsValueCheck(example1, 6, 4));
    printf("Example 2: %d\n", freqAsValueCheck(example2, 6, 3));
    printf("Example 3: %d\n", freqAsValueCheck(example3, 4, 3));
    printf("Example 4: %d\n", freqAsValueCheck(example4, 2, 2));
    printf("Example 5: %d\n", freqAsValueCheck(example5, 4, 4));
    printf("Example 6: %d\n", freqAsValueCheck(example6, 3, 4));
    printf("Example 7: %d\n", freqAsValueCheck(example7, 0, 3));
    printf("Example 8: %d\n", freqAsValueCheck(example8, 5, 3));
    printf("Example 9: %d\n", freqAsValueCheck(example9, 3, 3));
    printf("Example 10: %d\n", freqAsValueCheck(example10, 1, 2));
}