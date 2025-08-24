#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void printArr(int *arr) {
    for (size_t i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int *createArray() {
    int *myArr = (int *)malloc(SIZE * sizeof(int));

    if (!myArr) {
        printf("You've got some error, check your memory");
        exit(1);
    }

    printf("Enter %d elements to your array.\n", SIZE);
    for (size_t i = 0; i < SIZE; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &myArr[i]);
    }

    return myArr;
}

int main() {
    int *arr = createArray();

    printArr(arr);

    free(arr);

    return 0;
}