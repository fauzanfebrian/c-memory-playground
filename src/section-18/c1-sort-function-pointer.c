#include <stdio.h>
#include <stdlib.h>

int ascending(int a, int b) {
    return a > b ? 1 : 0;
}

int descending(int a, int b) {
    return a < b ? 1 : 0;
}

void printArr(int* arr, int n) {
    printf("Arr: ");
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sort(int* arr, int n, int (*diff)(int, int)) {
    if (n < 2) {
        return;
    }

    int swapped, i;

    do {
        swapped = 0;
        for (size_t i = 0; i < n - 1; i++) {
            if (diff(arr[i], arr[i + 1]) == 1) {
                swapped = 1;
                arr[i] = arr[i] ^ arr[i + 1];
                arr[i + 1] = arr[i] ^ arr[i + 1];
                arr[i] = arr[i] ^ arr[i + 1];
            }
        }
    } while (swapped != 0);
}

int main() {
    int arr[3] = {3, 1, 2};

    printArr(arr, 3);
    sort(arr, 3, descending);
    printArr(arr, 3);

    return 0;
}