#include <stdio.h>
#include <stdlib.h>

int main() {
    int arraySize;

    printf("Input the size of the array: ");
    scanf("%d", &arraySize);

    int *a = (int *)calloc(arraySize, sizeof(int));

    printf("First index: %d", *a);

    free(a);
    a = NULL;  // disabling the dangling pointer
}