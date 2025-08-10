#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void *a, void *b, size_t size) {  // in assumption size > 0
    void *tempMemory = malloc(size);

    memcpy(tempMemory, a, size);
    memcpy(a, b, size);
    memcpy(b, tempMemory, size);

    free(tempMemory);
}

void intSwap(int *a, int *b) {
    // clearance
    // int tempA = *a;
    // *a = *b;
    // *b = tempA;

    if (a != b) {
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
}

int main() {
    int num1, num2;

    printf("Enter num1: ");
    scanf("%d", &num1);

    printf("Enter num2: ");
    scanf("%d", &num2);

    printf("before swap a=%d, b=%d\n", num1, num2);
    intSwap(&num1, &num2);
    printf("after swap a=%d, b=%d\n", num1, num2);

    // multiple inderiction
    int c = 5;
    int *ptr1 = &c;
    int **ptr2 = &ptr1;

    printf("A=%p, ptr1=%p, ptr2=%p\n", &c, &ptr1, &ptr2);

    // swap generic different size
    int numInt = 10;
    double numDouble = 20.55;

    printf("before swap a=%.2f, b=%.2f\n", (double)numInt, numDouble);
    swap(&numInt, &numDouble, sizeof(int));
    printf("after swap double a=%.2f, b=%.2f\n", (double)numInt, numDouble);

    return 0;
}