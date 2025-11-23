#include <stdlib.h>
#include <stdio.h>

int findDominantValue(int* arr, int size) {
    if (size < 1) {
        return -1;
    }

    int* countArr = calloc(sizeof(int), size + 1);

    for (size_t i = 0; i < size; i++) {
        countArr[arr[i]]++;

        if (countArr[arr[i]] > size / 2) {
            free(countArr);
            return arr[i];
        }
    }

    free(countArr);
    return -1;
}

int main() {
    int example1[] = {3, 5, 4, 3, 3};        // dominant 3
    int example2[] = {3, 5, 4, 2, 3};        // no dominant value
    int example3[] = {1, 1, 1, 1, 1};        // all same
    int example4[] = {2, 2, 3, 3, 3, 3};     // 3 dominates
    int example5[] = {0, 0, 1, 0};           // 0 dominates
    int example6[] = {};                     // empty array
    int example7[] = {9};                    // single element
    int example8[] = {4, 4, 4, 2, 2, 2};     // no majority, equal halves
    int example9[] = {6, 1, 6, 2, 6, 3, 6};  // 6 dominates
    int example10[] = {100, 100, 100, 50};   // values exceed size, still works but stupid

    printf("Example 1: %d\n", findDominantValue(example1, 5));
    printf("Example 2: %d\n", findDominantValue(example2, 5));
    printf("Example 3: %d\n", findDominantValue(example3, 5));
    printf("Example 4: %d\n", findDominantValue(example4, 6));
    printf("Example 5: %d\n", findDominantValue(example5, 4));
    printf("Example 6: %d\n", findDominantValue(example6, 0));
    printf("Example 7: %d\n", findDominantValue(example7, 1));
    printf("Example 8: %d\n", findDominantValue(example8, 6));
    printf("Example 9: %d\n", findDominantValue(example9, 7));
    printf("Example 10: %d\n", findDominantValue(example10, 4));
}