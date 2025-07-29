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

void inputArray(int *arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("Enter value #%d: ", i + 1);
        scanf("%d", arr);
        arr++;
    }
}

void displayArray(int *arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("Value #%d: %d\n", i + 1, *arr);
        arr++;
    }
}

int main() {
    int grades[SIZE];
    inputArray(grades, SIZE);

    displayArray(grades, SIZE);

    int summed = sumArray(grades, SIZE);
    printf("Sum = %d\n", summed);

    int isKeyInArray = findIfKeyInArray(grades, SIZE, 60);
    printf("Key 60 in array: %d", isKeyInArray);

    return 0;
}