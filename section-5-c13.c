#include <stdio.h>
#include <stdlib.h>

void printArrA(int *arr, size_t size) {
    if (size < 1) {
        printf("\n");
        return;
    }

    printf(" %d", arr[size - 1]);
    printArrA(arr, size - 1);
}

void printArrB(int *arr, size_t size) {
    if (size < 1) {
        return;
    }

    printf(" %d", arr[0]);
    printArrA(arr + 1, size - 1);
}

int main() {
    int arr[5] = {-2, -2, 3, -2, 1};

    printf("print A:");
    printArrA(arr, 5);
    printf("print B:");
    printArrB(arr, 5);

    return 0;
}
