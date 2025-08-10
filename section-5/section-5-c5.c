#include <stdio.h>
#include <stdlib.h>

int isSortedIterative(int *pArr, size_t size, int *isReallySorted) {
    *isReallySorted = 1;

    for (size_t i = 0; i < size - 1; i++) {
        if (pArr[i] > pArr[i + 1]) {
            *isReallySorted = 0;
            return 0;
        }

        if (pArr[i] == pArr[i + 1]) {
            *isReallySorted = 0;
        }
    }

    return 1;
}

int isSortedRecursive(int *pArr, size_t size, int *isReallySorted) {
    if (size == 1) {
        *isReallySorted = 1;
        return 1;
    }
    int result = isSortedRecursive(pArr, size - 1, isReallySorted);
    if (!result) {
        return result;
    }
    if (pArr[size - 1] == pArr[size - 2]) {
        *isReallySorted = 0;
    }
    if (pArr[size - 1] < pArr[size - 2]) {
        *isReallySorted = 0;
        return 0;
    }
    return result;
}

int main() {
    int arr1[1000];
    int arr2[1000];
    int arr3[1000];

    for (int i = 0; i < 1000; ++i) {
        arr1[i] = i;                    // sorted ascending
        arr2[i] = i / 10;               // grouped 10s (e.g., 0,0,0...1,1,1...) → non-strict ascending
        arr3[i] = (91 * i + 37) % 100;  // pseudo-random chaos
    }

    int arr1P, arr2P, arr3P;

    printf("arr1 sort level (Iterative): %d\n", isSortedIterative(arr1, 100, &arr1P) + arr1P);
    printf("arr2 sort level (Iterative): %d\n", isSortedIterative(arr2, 100, &arr2P) + arr2P);
    printf("arr3 sort level (Iterative): %d\n", isSortedIterative(arr3, 100, &arr3P) + arr3P);

    printf("arr1 sort level (Recursive): %d\n", isSortedRecursive(arr1, 100, &arr1P) + arr1P);
    printf("arr2 sort level (Recursive): %d\n", isSortedRecursive(arr2, 100, &arr2P) + arr2P);
    printf("arr3 sort level (Recursive): %d\n", isSortedRecursive(arr3, 100, &arr3P) + arr3P);

    return 0;
}
