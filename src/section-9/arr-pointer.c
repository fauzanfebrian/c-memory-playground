#include <stdio.h>
#include <stdlib.h>

int main() {
    int* arr[5];

    for (size_t i = 0; i < 5; i++) {
        arr[i] = (int*)calloc(3, sizeof(int));
    }

    arr[1][1] = 30;
    scanf("%d", &arr[0][2]);
    printf("Arr[0][2] == %d", arr[0][2]);

    int* arrDynamic[5];

    arrDynamic[0] = (int*)calloc(1, sizeof(int));
    arrDynamic[1] = (int*)calloc(2, sizeof(int));
    arrDynamic[2] = (int*)calloc(2, sizeof(int));
    arrDynamic[3] = (int*)calloc(3, sizeof(int));
    arrDynamic[4] = (int*)calloc(3, sizeof(int));

    return 0;
}