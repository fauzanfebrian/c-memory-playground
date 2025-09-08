#include <stdio.h>
#include <stdlib.h>

int main() {
    int** arr;

    int rows, columns;

    printf("Please enter size of the rows: ");
    scanf("%d", &rows);

    arr = calloc(rows, sizeof(int*));

    for (size_t i = 0; i < rows; i++) {
        printf("Please enter size of the column %d: ", i + 1);
        scanf("%d", &columns);
        arr[i] = calloc(3, sizeof(int));
    }

    return 0;
}