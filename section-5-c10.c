#include <stdio.h>
#include <stdlib.h>

int palindromeRecursiveValidation(int *arr, size_t size) {
    if (size <= 1) {
        return 1;
    }

    if (arr[0] == arr[size - 1]) {
        return palindromeRecursiveValidation(arr + 1, size - 2);
    }

    return 0;
}

int main() {
    int arr[5] = {1, -2, 3, -2, 1};

    printf("arr palindrome: %d", palindromeRecursiveValidation(arr, 5));

    return 0;
}
