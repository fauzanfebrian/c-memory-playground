#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void printArr(int *arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int *createArray() {
    int size;
    printf("Enter the size of elements to the array.\n");
    scanf("%d", &size);

    int *myArr = (int *)malloc(size * sizeof(int));

    if (!myArr) {
        printf("You've got some error, check your memory");
        exit(1);
    }

    printf("Enter %d elements to your array.\n", size);
    for (size_t i = 0; i < size; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &myArr[i]);
    }

    printArr(myArr, size);

    return myArr;
}

int main() {
    int *arr = createArray();

    free(arr);

    return 0;
}