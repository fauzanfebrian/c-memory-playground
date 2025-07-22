#include <stdio.h>

int *findMaxIntPointer(int *num1, int *num2) {
    return *num1 > *num2 ? num1 : num2;
}

void sortMinMax(int num1, int num2, int **pMax, int **pMin) {
    // assign pointer jika NULL
    if (*pMax == NULL) {
        static int tempMax;
        *pMax = &tempMax;
    }
    if (*pMin == NULL) {
        static int tempMin;
        *pMin = &tempMin;
    }

    **pMax = (num1 > num2) ? num1 : num2;
    **pMin = (num1 < num2) ? num1 : num2;
}

int main() {
    int grade1 = 80, grade2 = 100;
    int *ptr1 = NULL, *ptr2 = NULL;

    printf("Grade1 VALUE = %d\n", grade1);
    printf("Grade1 ADDRESS = %p\n", &grade1);

    printf("Grade2 VALUE = %d\n", grade2);
    printf("Grade2 ADDRESS = %p\n", &grade2);

    int *greatGrade = findMaxIntPointer(&grade1, &grade2);

    printf("Great Grade = %p (%d)\n", greatGrade, *greatGrade);

    sortMinMax(grade1, grade2, &ptr1, &ptr2);

    printf("Min<%p> = %d, Max<%p> = %d\n", ptr1, *ptr1, ptr2, *ptr2);

    ptr1 = &grade1;
    ptr2 = &grade2;

    grade1 = *ptr2;
    grade2 = grade1 - 3;

    printf("grade1 = %d, grade2 = %d", *ptr1, *ptr2);

    return 0;
}