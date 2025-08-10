#include <stdio.h>

#define SIZE 4

int sumArray(int *arr, size_t size) {
    int sum = 0;
    for (size_t i = 0; i < size; i++) {
        sum += *arr;
        arr++;
    }
    return sum;
}

int main() {
    int grades[SIZE] = {89, 86, 79, 100};
    int total = sumArray(grades, SIZE);

    double average = (double)total / (double)SIZE;

    printf("average of the grades is: %.2lf, total: %d", average, total);

    return 0;
}