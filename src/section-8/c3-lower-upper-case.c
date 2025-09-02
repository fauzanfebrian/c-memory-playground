#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int size) {
    printf("Array <%p>: ", arr);
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void generateOddEvenArray(int *ogArr, int size, int **oddArr, int **evenArr) {
    int oddSize = 0;

    for (size_t i = 0; i < size; i++) {
        if (ogArr[i] % 2 != 0) {
            oddSize++;
        }
    }

    *oddArr = malloc(oddSize * sizeof(int));
    *evenArr = malloc((size - oddSize) * sizeof(int));

    int iOdd = 0,
        iEven = 0;

    for (size_t i = 0; i < size; i++) {
        if (ogArr[i] % 2 != 0) {
            (*oddArr)[iOdd] = ogArr[i];
            iOdd++;
        } else {
            (*evenArr)[iEven] = ogArr[i];
            iEven++;
        }
    }
}

int main() {
    int ogArray[] = {12, 5, 7, 8, 3, 10, 4, 9};

    int *oddArray, *evenArray;

    generateOddEvenArray(ogArray, 8, &oddArray, &evenArray);

    printArray(oddArray, 8);
    printArray(evenArray, 8);

    return 0;
}