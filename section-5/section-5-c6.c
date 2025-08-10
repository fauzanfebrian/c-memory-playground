#include <stdio.h>
#include <stdlib.h>

void swap(char *p1, char *p2) {
    if (p1 == p2) {
        return;
    }

    *p1 = *p1 ^ *p2;
    *p2 = *p1 ^ *p2;
    *p1 = *p1 ^ *p2;
}

void reverseIterative(char *pArr, size_t size) {
    for (size_t i = 0; i < size / 2; i++) {
        swap(&pArr[i], &pArr[size - i - 1]);
    }
}

void reverseRecursive(char *pArr, size_t size) {
    if (size > 1) {
        swap(&pArr[0], &pArr[size - 1]);
        reverseRecursive(pArr + 1, size - 2);
    }
}

void printArr(char *pArr, size_t size) {
    printf("Array Value: ");
    for (size_t i = 0; i < size; i++) {
        printf("%c", pArr[i]);
    }
    printf("\n");
}

int main() {
    char arr[5] = {'a', 'f', 'L', 'k', 'd'};

    printArr(arr, 5);
    reverseIterative(arr, 5);
    printArr(arr, 5);
    reverseRecursive(arr, 5);
    printArr(arr, 5);

    return 0;
}
