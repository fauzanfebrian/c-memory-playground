#include <stdio.h>
#include <stdlib.h>

int printArr(int *arr, size_t size) {
    printf("Arr <%p>: ", arr);
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void *deleteFromArray(void *arr, size_t elementCount, size_t elementSize, size_t removeIndex) {
    // allocate new memory
    unsigned char *newArr = malloc(elementCount - elementSize);
    if (newArr == NULL) {
        return NULL;
    }

    int arrIndex = 0;

    for (size_t i = 0; i < elementCount; i++) {
        if (i / elementSize == removeIndex) {
            continue;
        }

        newArr[arrIndex] = ((unsigned char *)arr)[i];
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

    ptr = (int *)deleteFromArray(ptr, sizeof(arr), sizeof(arr[0]), 2);

    printArr(ptr, 3);

    free(ptr);

    return 0;
}