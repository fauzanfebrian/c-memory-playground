#include <stdio.h>
#include <stdlib.h>

int printArr(int *arr, size_t size) {
    printf("Arr <%p>: ", arr);
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void *insertValueToArray(void *arr, size_t elementCount, size_t elementSize, size_t insertIndex, void *insertValue) {
    size_t newMemSize = elementCount + elementSize;

    // allocate new memory
    unsigned char *newArr = malloc(newMemSize);
    if (newArr == NULL) {
        return NULL;
    }

    int arrIndex = 0;

    for (size_t i = 0; i < newMemSize; i++) {
        if (i / elementSize == insertIndex) {
            newArr[i] = ((unsigned char *)insertValue)[i % elementSize];
            continue;
        }

        newArr[i] = ((unsigned char *)arr)[arrIndex];
        arrIndex++;
    }

    // make this outside of this function, cause i dunno where the array came from. it may came from Stack memory, which is this function can do nothing about it.
    // free(arr);

    return (void *)newArr;
}

int main() {
    int arr[] = {1, 3, 4, 5};
    int *ptr = arr;

    printArr(ptr, 4);

    int newValue = 2;
    ptr = (int *)insertValueToArray(ptr, sizeof(arr), sizeof(arr[0]), 1, (void *)&newValue);

    printArr(ptr, 5);

    free(ptr);

    return 0;
}