#include <stdio.h>
#include <stdlib.h>

short int getSignBitValue(int *num) {
    return (*num >> (sizeof(*num) * 8 - 1)) & 1;
}

int exchangingSignChecker(int *arr, size_t size) {
    if (size <= 1) {
        return 1;
    }

    // if ((arr[0] >= 0 && arr[1] >= 0) || (arr[0] < 0 && arr[1] < 0)) {
    if (getSignBitValue(arr) + getSignBitValue(arr + 1) != 1) {
        return 0;
    }

    return exchangingSignChecker(arr + 1, size - 1);
}

int main() {
    int arr[5] = {-2, -2, 3, -2, 1};

    printf("sign checker: %d", exchangingSignChecker(arr, 5));

    return 0;
}
