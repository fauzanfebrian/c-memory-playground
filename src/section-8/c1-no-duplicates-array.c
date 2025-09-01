#include <stdio.h>
#include <stdlib.h>

int *createNoDuplexArray(int *ogArr, size_t ogSize, int *arrSize) {
    if (ogSize == 0) {
        return NULL;
    }

    int *noDuplexArr = NULL;

    int dynamicSize = 0;
    *arrSize = 0;

    for (size_t i = 0; i < ogSize; i++) {
        if (*arrSize > 0 && ogArr[i] == noDuplexArr[*arrSize - 1]) {
            continue;
        }

        *arrSize += 1;
        if (*arrSize > dynamicSize) {
            dynamicSize = dynamicSize > 0 ? dynamicSize * 2 : 4;
            noDuplexArr = realloc(noDuplexArr, dynamicSize * sizeof(int));
        }

        noDuplexArr[*arrSize - 1] = ogArr[i];
    }

    if (dynamicSize > *arrSize) {
        noDuplexArr = realloc(noDuplexArr, *arrSize * sizeof(int));
    }

    return noDuplexArr;
}

// THIS CODE FROM VLAD
int *vladCreateNoDuplexArray(int *ogArr, size_t ogSize, int *arrSize) {
    int i = 0, j = 0;
    *arrSize = 1;
    int *noDuplexArr;

    for (i = 0; i < ogSize - 1; i++) {
        if (ogArr[i] != ogArr[i + 1]) {
            *arrSize += 1;
        }
    }

    noDuplexArr = malloc(*arrSize * sizeof(int));

    for (i = 0; i < ogSize - 1; i++) {
        if (ogArr[i] != ogArr[i + 1]) {
            noDuplexArr[j] = ogArr[i];
            j++;
        }
    }

    noDuplexArr[j] = ogArr[i];

    return noDuplexArr;
}

void printArr(int *arr, size_t size) {
    printf("Arr <%p>", arr);

    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main() {
    int ogArr[] = {1, 2, 3, 4, 5, 6, 7, 7, 7, 7, 8, 8, 9, 9};
    int ogSize = sizeof(ogArr) / sizeof(ogArr[0]);
    int newSize;

    printArr(ogArr, ogSize);

    int *noDuplexArr = createNoDuplexArray(ogArr, ogSize, &newSize);

    printArr(noDuplexArr, newSize);
    free(noDuplexArr);

    return 0;
}