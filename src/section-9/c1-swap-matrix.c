#include <stdio.h>
#include <stdlib.h>

void print2DDynamicMatrix(int **a, int rows, int columns) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            printf("%9d", a[i][j]);
        }
        printf("\n");
    }
}

void swapRows(int **a, int **b) {
    if (a == b) {
        return;
    }

    *a = (int *)((uintptr_t)(*a) ^ (uintptr_t)(*b));
    *b = (int *)((uintptr_t)(*a) ^ (uintptr_t)(*b));
    *a = (int *)((uintptr_t)(*a) ^ (uintptr_t)(*b));
}

void swapColumns(int *a, int *b) {
    if (a == b) {
        return;
    }

    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main() {
    int rowA[] = {1, 6, 4, 3, 2};
    int rowB[] = {5, 2, 3, 4, 9};
    int rowC[] = {9, 1, 4, 6, 7};

    int *matrix[] = {rowA, rowB, rowC};

    print2DDynamicMatrix(matrix, 3, 5);

    swapRows(&matrix[0], &matrix[2]);

    printf("After swap rows:\n");
    print2DDynamicMatrix(matrix, 3, 5);

    swapColumns(&matrix[0][0], &matrix[2][1]);

    printf("After swap columns:\n");
    print2DDynamicMatrix(matrix, 3, 5);

    return 0;
}