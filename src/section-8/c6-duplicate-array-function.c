#include <stdio.h>
#include <stdlib.h>

void printArr(int *pArr, size_t size) {
    printf("Arr value <%p>:", (void *)pArr);
    for (size_t i = 0; i < size; i++) {
        printf(" %d", pArr[i]);
    }
    printf("\n");
}

void duplicateArray(void *arr, size_t size, void **arrLoc) {
    // allocate new memory
    unsigned char *newBlock = malloc(size);
    if (newBlock == NULL) {
        return;
    }

    for (size_t i = 0; i < size; i++) {
        newBlock[i] = ((unsigned char *)arr)[i];
    }

    *arrLoc = (void *)newBlock;
}

int main() {
    int arr[] = {1, 2, 3, 5, 3, 3, 6, 7};

    printArr(arr, 8);

    int *newArr;

    duplicateArray(arr, sizeof(arr), (void **)&newArr);

    printArr(newArr, 8);

    free(newArr);
}