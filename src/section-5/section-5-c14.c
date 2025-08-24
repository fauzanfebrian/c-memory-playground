#include <stdio.h>
#include <stdlib.h>

double sumRecursive(int *arr, size_t size) {
    if (size <= 1) {
        return (double)*arr;
    }
    return (double)*arr + sumRecursive(arr + 1, size - 1);
}

double findAVGRecursive(int *arr, size_t size) {
    // return sumRecursive(arr, size) / (double)size;
    if (size <= 1) {
        return *arr;
    }
    double avgSoFar = findAVGRecursive(arr + 1, size - 1);
    double res = (avgSoFar * (size - 1) + *arr) / size;
    printf("(%.2f * (%d - 1) + %d) / %d: %.2f\n", avgSoFar, size, *arr, size, res);
    return res;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    printf("average: %.2f", findAVGRecursive(arr, 5));

    return 0;
}
