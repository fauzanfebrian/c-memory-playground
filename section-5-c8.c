#include <stdio.h>
#include <stdlib.h>

void printArrFrequencies(int *arr, size_t size) {
    size_t i, j;
    int leftFlag = 0;
    int countValue = 0;

    for (i = 0; i < size; i++) {
        countValue = 1;
        leftFlag = 0;
        for (j = 0; j < i; j++) {
            if (arr[j] == arr[i]) {
                leftFlag = 1;
                break;
            }
        }
        if (leftFlag == 1) {
            continue;
        }
        for (j = i + 1; j < size; j++) {
            if (arr[j] == arr[i]) {
                countValue++;
            }
        }

        printf("Total int %d: %d\n", arr[i], countValue);
    }
}

int main() {
    int arr[5] = {5, 6, 7, 6, 5};
    printArrFrequencies(arr, 5);

    return 0;
}
