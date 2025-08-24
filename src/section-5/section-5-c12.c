#include <stdio.h>
#include <stdlib.h>

void find2MaxValRecursive(int *arr, size_t size, int *max1, int *max2) {
    if (size <= 1) {
        *max1 = *arr;
        *max2 = *arr;
        return;
    }

    find2MaxValRecursive(arr + 1, size - 1, max1, max2);

    if (*arr >= *max1) {
        *max2 = *max1;
        *max1 = *arr;
        return;
    }

    if (*arr > *max2) {
        *max2 = *arr;
    }
}

int findMax2AdjacentElements(int *arr, size_t size) {
    int max1, max2;

    find2MaxValRecursive(arr, size, &max1, &max2);

    return max1 + max2;
}

int main() {
    int arr[5] = {2, 9, 3, 2, 1};

    printf("Max value: %d", findMax2AdjacentElements(arr, 5));

    return 0;
}
