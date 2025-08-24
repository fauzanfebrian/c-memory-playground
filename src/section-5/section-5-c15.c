#include <stdio.h>
#include <stdlib.h>

int checkSortedFloatingPoint(double *arr, size_t size) {
    if (size == 1) {
        return 1;
    }

    if ((int)*arr > (int)*(arr + 1)) {
        return 0;
    }

    if (*arr - (double)(int)*arr > *(arr + 1) - (double)(int)*(arr + 1)) {
        return 0;
    }

    return checkSortedFloatingPoint(arr + 1, size - 1);
}

int main() {
    double arr[5] = {-2, -1, 1.3, 2.4, 3.7};

    printf("is sorted: %d", checkSortedFloatingPoint(arr, 5));

    return 0;
}
