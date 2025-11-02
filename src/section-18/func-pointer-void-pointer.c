#include <stdio.h>
#include <stdbool.h>

void printInt(void* a) {
    printf("%d ", *(int*)a);
}

void printFloat(void* a) {
    printf("%.2f ", *(float*)a);
}

void printDouble(void* a) {
    printf("%.2lf ", *(double*)a);
}

void performOperation(void* arr, int arrLength, int elemSize, void (*operation)(void*)) {
    for (size_t i = 0; i < arrLength; i++) {
        operation((char*)arr + i * elemSize);
    }
    printf("\n");
}

int main() {
    // integer array
    int arrInt[] = {1, 2, 3};
    performOperation(arrInt, 3, sizeof(int), printInt);
    // float array
    float arrFloat[] = {1.1, 2.2, 3.3};
    performOperation(arrFloat, 3, sizeof(float), printFloat);

    double arrDouble[] = {1.2, 2.3, 3.4};
    performOperation(arrDouble, 3, sizeof(double), printDouble);

    return 0;
}