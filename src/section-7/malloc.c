#include <stdio.h>
#include <stdlib.h>

int main() {
    double *bArr;
    int arraySize;

    scanf("%d", &arraySize);
    bArr = (double *)malloc(sizeof(double) * 2);
    if (bArr != NULL) {
        printf("Allocation, Succeeded");
    }

    printf("Allocation Failed");

    free(bArr);
}