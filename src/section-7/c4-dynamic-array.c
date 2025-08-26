#include <stdio.h>
#include <stdlib.h>

#define SIZE_MULTIPLIER 1.5

void printArr(int *ptr, size_t size) {
    if (!size) {
        printf("Array not itialized.");
        return;
    }

    printf("Array <%p>: ", ptr);
    for (size_t i = 0; i < size; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
}

void handleDynamicArray(int **arr, size_t *dynamicSize, size_t currentSize, int newValue) {
    if (currentSize > *dynamicSize) {
        *dynamicSize = (int)(currentSize * SIZE_MULTIPLIER);
        if (*arr == NULL) {
            int *newArr = malloc(*dynamicSize * sizeof(int));
            if (!newArr) {
                printf("Error memory");
                return;
            }
            *arr = newArr;
        } else {
            int *newArr = realloc(*arr, *dynamicSize * sizeof(int));
            if (!newArr) {
                printf("Error memory");
                return;
            }
            *arr = newArr;
        }
    }

    (*arr)[currentSize - 1] = newValue;
}

void handleFreeMultiplier(int **arr, size_t actualSize) {
    if (actualSize == 0) {
        *arr = NULL;
    }

    int *newTemp = realloc(*arr, actualSize);
    if (newTemp) {
        *arr = newTemp;
    }
}

int main() {
    int *dynamicArr = NULL;
    size_t dynamicCurrentSize = 0;
    size_t actualSize = 0;

    while (1) {
        int newVal;

        printf("Masukkan angka: ");
        scanf("%d", &newVal);

        if (newVal == -1) {
            handleFreeMultiplier(&dynamicArr, actualSize);
            break;
        }

        actualSize++;
        handleDynamicArray(&dynamicArr, &dynamicCurrentSize, actualSize, newVal);
    }

    printArr(dynamicArr, actualSize);
    free(dynamicArr);

    return 0;
}