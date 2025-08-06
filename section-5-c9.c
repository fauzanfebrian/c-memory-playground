#include <stdio.h>
#include <stdlib.h>

int find2PairIndex(int *arr, size_t size, int sum, int *index1, int *index2) {
    if (size < 2) {
        return 0;
    }

    for (size_t i = 0; i < size; i++) {
        for (size_t j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == sum) {
                *index1 = i;
                *index2 = j;
                return 1;
            }
        }
    }

    return 0;
}

int find2PairIndexOptimized(int *arr, size_t size, int sum, int *index1, int *index2) {
    if (size < 2) {
        return 0;
    }

    int i = 0, j = size - 1;

    while (i != j) {
        if (arr[i] + arr[j] == sum) {
            *index1 = i;
            *index2 = j;
            return 1;
        }

        if (arr[i] + arr[j] < sum) {
            i++;
            continue;
        }

        if (arr[i] + arr[j] > sum) {
            j--;
            continue;
        }
    }

    return 0;
}

int main() {
    int arr[6] = {1, 3, 4, 5, 9, 13};

    int value = 4;
    int index1, index2;

    int isFound = find2PairIndexOptimized(arr, 5, value, &index1, &index2);

    if (isFound) {
        printf("Value of %d, can be summed with value at index %d and %d", value, index1, index2);
    } else {
        printf("Value of %d, can't be found anywhere", value);
    }

    return 0;
}
