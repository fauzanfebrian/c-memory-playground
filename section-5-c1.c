#include <stdio.h>

#define SIZE 4

int findMaxValue(int *arr, size_t size) {
    if (size <= 0) {
        return -1;
    }

    int maxNow = *arr;
    for (size_t i = 0; i < size; i++) {
        if (maxNow < *arr) {
            maxNow = *arr;
        }
        arr++;
    }

    return maxNow;
}

int main() {
    int grades[SIZE] = {80, 99, 0, 72};
    int maxGrade = findMaxValue(grades, SIZE);

    printf("max size of grades is: %d", maxGrade);

    return 0;
}