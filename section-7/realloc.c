#include <stdio.h>
#include <stdlib.h>

int main() {
    double *bArr;
    int arraySize;

    printf("Enter arr size: ");
    scanf("%d", &arraySize);
    bArr = (double *)malloc(sizeof(double) * arraySize);
    if (bArr == NULL) {
        printf("Allocation Failed\n");
        exit(1);
    }

    printf("Allocation, Succeeded\n");

    // to avoid bArr pointer missing
    double *temp = (double *)realloc(bArr, sizeof(double) * (arraySize + 1));
    if (temp == NULL) {
        printf("ReAllocation Failed\n");
        exit(1);
    }

    bArr = temp;
    printf("ReAllocation, Succeeded\n");

    bArr[arraySize] = 90.9;

    printf("%.2f", bArr[arraySize]);

    free(bArr);
}