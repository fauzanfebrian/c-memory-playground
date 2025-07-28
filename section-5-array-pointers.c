#include <stdio.h>

#define SIZE 4

int sumArray(int *ptr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += ptr[i];
    }
    return sum;
}

int findIfKeyInArray(int *arr, int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int grades[SIZE] = {3, 5, 7, 8};

    int summed = sumArray(grades, SIZE);
    printf("Sum = %d\n", summed);

    int isKeyInArray = findIfKeyInArray(grades, SIZE, 60);
    printf("Key 60 in array: %d", isKeyInArray);

    return 0;
}