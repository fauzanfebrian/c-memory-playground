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

void freeMatrix(int **a, int rows) {
    for (size_t i = 0; i < rows; i++) {
        free(a[i]);
    }
    free(a);
}

int **alocate2DMatrix() {
    int rows;

    printf("Enter number of rows for the 2D Matix: ");
    scanf("%d", &rows);

    int **a = calloc(rows, sizeof(int *));
    if (!a) {
        return NULL;
    }

    for (size_t i = 0; i < rows; i++) {
        int columns;

        printf("Enter number of colums for row %d: ", i + 1);
        scanf("%d", &columns);

        a[i] = calloc(columns, sizeof(int));
        if (!a[i]) {
            freeMatrix(a, i);

            return NULL;
        }
    }

    return a;
}

int **alocate2DMatrixV2(size_t rows, size_t columns) {
    int **a = calloc(rows, sizeof(int *));
    if (!a) {
        return NULL;
    }

    for (size_t i = 0; i < rows; i++) {
        a[i] = calloc(columns, sizeof(int));
        if (!a[i]) {
            freeMatrix(a, i);

            return NULL;
        }
    }

    return a;
}

int main() {
    int rows, columns;

    printf("Enter number of rows for the 2D Matix: ");
    scanf("%d", &rows);

    printf("Enter number of colums: ");
    scanf("%d", &columns);

    int **myMatrix = alocate2DMatrixV2(rows, columns);
    print2DDynamicMatrix(myMatrix, rows, columns);
    freeMatrix(myMatrix, rows);

    return 0;
}