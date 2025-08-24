#include <stdio.h>
#include <stdlib.h>

int *createArr(size_t size) {
    int *arr = (int *)malloc(size * sizeof(int));

    for (size_t i = 0; i < size; i++) {
        arr[i] = i;
    }

    return arr;
}

void printArr(int *pArr, size_t size) {
    printf("Arr value <%p>:", (void *)pArr);
    for (size_t i = 0; i < size; i++) {
        printf(" %d", pArr[i]);
    }
    printf("\n");
}

void *myRealloc(void *srcBlock, size_t oldMemSize, size_t newMemSize) {
    // allocate new memory
    unsigned char *newBlock = malloc(newMemSize);
    if (newBlock == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < oldMemSize && i < newMemSize; i++) {
        newBlock[i] = ((unsigned char *)srcBlock)[i];
    }

    free(srcBlock);

    return (void *)newBlock;
}

int main() {
    int *arr = createArr(10);

    printArr(arr, 10);

    int *newArr = (int *)myRealloc(arr, 10 * sizeof(int), 20 * sizeof(int));
    if (newArr == NULL) {
        printf("Error when allocate a memory");
        exit(1);
    }

    arr = newArr;

    printArr(arr, 20);

    free(arr);
}