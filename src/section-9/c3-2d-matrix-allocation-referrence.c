#include <stdio.h>
#include <stdlib.h>

void print2DDynamicMatrix(int** a, int rows, int columns) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            printf("%9d", a[i][j]);
        }
        printf("\n");
    }
}

void allocate2DMatrixByRef(int*** ref, int* rows, int* columns) {
    printf("Enter total rows: ");
    scanf("%d", rows);

    printf("Enter total columns: ");
    scanf("%d", columns);

    *ref = calloc(*rows, sizeof(int*));

    for (size_t i = 0; i < *rows; i++) {
        (*ref)[i] = calloc(*columns, sizeof(int));

        for (size_t j = 0; j < *columns; j++) {
            (*ref)[i][j] = 69;
        }
    }
}

int main() {
    int **matrix, rows, columns;

    allocate2DMatrixByRef(&matrix, &rows, &columns);
    print2DDynamicMatrix(matrix, rows, columns);

    return 0;
}