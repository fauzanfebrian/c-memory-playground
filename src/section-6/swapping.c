#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void swap(int *val1, int *val2) {
    *val1 = *val1 ^ *val2;
    *val2 = *val1 ^ *val2;
    *val1 = *val1 ^ *val2;
}

void swapArrON(int *arr1, int *arr2) {
    for (size_t i = 0; i < SIZE; i++) {
        swap(arr1 + i, arr2 + i);
    }
}

void swapArrO1(void **ptr1, void **ptr2) {
    // uintptr_t itu unsigned integer dengan ukuran sama kayak pointer
    *ptr1 = (void *)((uintptr_t)(*ptr1) ^ (uintptr_t)(*ptr2));
    *ptr2 = (void *)((uintptr_t)(*ptr1) ^ (uintptr_t)(*ptr2));
    *ptr1 = (void *)((uintptr_t)(*ptr1) ^ (uintptr_t)(*ptr2));
}

void printArr(int *arr, size_t size) {
    printf("Value: ");
    for (size_t i = 0; i < size; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

int *generateArr(int size) {
    int *arr = (int *)malloc(size * sizeof(int));
    for (size_t i = 0; i < size; i++) {
        *(arr + i) = rand();
    }
    return arr;
}

int main() {
    int sizeArr1, sizeArr2;

    printf("Enter size for Array 1: ");
    scanf("%d", &sizeArr1);

    printf("Enter size for Array 2: ");
    scanf("%d", &sizeArr2);

    int *arr1 = generateArr(sizeArr1);
    int *arr2 = generateArr(sizeArr2);

    printf("Before swap\n");
    printArr(arr1, sizeArr1);
    printArr(arr2, sizeArr2);

    swapArrO1((void **)&arr1, (void **)&arr2);

    printf("After swap\n");
    printArr(arr1, sizeArr1);
    printArr(arr2, sizeArr2);

    free(arr1);
    free(arr2);

    int array1[SIZE] = {1, 3, 6, 8, 10};
    int array2[SIZE] = {10, 13, 46, 28, 8};

    printf("Before swap\n");
    printArr(array1, SIZE);
    printArr(array2, SIZE);

    swapArrON(array1, array2);

    printf("After swap\n");
    printArr(array1, SIZE);
    printArr(array2, SIZE);

    return 0;
}