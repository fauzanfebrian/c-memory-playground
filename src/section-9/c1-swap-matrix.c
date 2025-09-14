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

void swapRows(void **a, int row1, int row2) {
    if (row1 == row2) {
        return;
    }

    a[row1] = (void *)((uintptr_t)(a[row1]) ^ (uintptr_t)(a[row2]));
    a[row2] = (void *)((uintptr_t)(a[row1]) ^ (uintptr_t)(a[row2]));
    a[row1] = (void *)((uintptr_t)(a[row1]) ^ (uintptr_t)(a[row2]));
}

void swapColumns(int **a, size_t totalRows, int column1, int column2) {
    for (size_t i = 0; i < totalRows; i++) {
        a[i][column1] = a[i][column1] ^ a[i][column2];
        a[i][column2] = a[i][column1] ^ a[i][column2];
        a[i][column1] = a[i][column1] ^ a[i][column2];
    }
}

int main() {
    int rowA[] = {1, 6, 4, 3, 2};
    int rowB[] = {5, 2, 3, 4, 9};
    int rowC[] = {9, 1, 4, 6, 7};

    int *matrix[] = {rowA, rowB, rowC};

    print2DDynamicMatrix(matrix, 3, 5);

    swapRows((void *)matrix, 0, 2);

    printf("After swap rows:\n");
    print2DDynamicMatrix(matrix, 3, 5);

    swapColumns(matrix, 3, 0, 2);

    printf("After swap columns:\n");
    print2DDynamicMatrix(matrix, 3, 5);

    return 0;
}