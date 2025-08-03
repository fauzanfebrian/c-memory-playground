#include <stdio.h>
#include <stdlib.h>

int hasNeighbors(int *pArr, size_t size) {
    if (!size || !pArr) {
        return 0;
    }

    for (size_t i = 0; i < size; i++) {
        if (i == 0) {
            if (pArr[i + 1] == pArr[i]) {
                return 1;
            }
            continue;
        }

        if (i == size - 1) {
            if (pArr[i - 1] == pArr[i]) {
                return 1;
            }
            continue;
        }

        if (pArr[i - 1] + pArr[i + 1] == pArr[i]) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int arr1[5] = {1, 4, 7, 3, 2};
    int arr2[5] = {1, 4, 1, 4, 2};

    printf("arr1: %d\n", hasNeighbors(arr1, 5));
    printf("arr2: %d", hasNeighbors(arr2, 5));

    return 0;
}