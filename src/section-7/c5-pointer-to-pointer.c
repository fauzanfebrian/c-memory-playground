#include <stdio.h>
#include <stdlib.h>

void create1DByRef(size_t size, void **ptr) {
    *ptr = malloc(size);
    if (*ptr == NULL) {
        printf("Malloc Error");
        exit(1);
    }
}

int main() {
    int size;
    int *arr;

    printf("Enter the size of arr: ");
    scanf("%d", &size);

    create1DByRef(size * sizeof(int), (void **)&arr);

    for (size_t i = 0; i < size; i++) {
        arr[i] = i;
    }

    printf("Arr: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}