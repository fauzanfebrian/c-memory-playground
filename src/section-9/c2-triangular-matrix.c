#include <stdio.h>
#include <stdlib.h>

void print2DDynamicMatrix(int **a, int rows, int columns) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            printf("%13d", a[i][j]);
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

void printUpperTriangular(int **triangular, size_t size) {
    printf("Upper matrix:\n");
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            printf("%5d ", j < size - i ? triangular[i][j] : 0);
        }
        printf("\n");
    }
    printf("\n");
}

void printLowerTriangular(int **triangular, size_t size) {
    printf("Lower matrix:\n");
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            printf("%5d ", i >= j ? triangular[i][j] : 0);
        }
        printf("\n");
    }
    printf("\n");
}

int **generateUpperTriangular(size_t size) {
    int **triangular = calloc(size, sizeof(int *));

    for (size_t i = 0; i < size; i++) {
        triangular[i] = calloc(size - i, sizeof(int));
        for (size_t j = 0; j < size - i; j++) {
            triangular[i][j] = 69;
        }
    }

    return triangular;
}

int **generateLowerTriangular(size_t size) {
    int **triangular = calloc(size, sizeof(int *));

    for (size_t i = 0; i < size; i++) {
        triangular[i] = calloc(1 + i, sizeof(int));
        for (size_t j = 0; j < i + 1; j++) {
            triangular[i][j] = 69;
        }
    }

    return triangular;
}

int main() {
    int size = 3;

    int **upper = generateUpperTriangular(size);
    printUpperTriangular(upper, size);
    freeMatrix(upper, size);

    int **lower = generateLowerTriangular(size);
    printLowerTriangular(lower, size);
    freeMatrix(lower, size);

    return 0;
}