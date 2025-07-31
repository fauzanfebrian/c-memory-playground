#include <stdio.h>
#include <stdlib.h>

void minMax(int *pArr, size_t size, int *min, int *max) {
    *min = *pArr;
    *max = *pArr;

    pArr++;

    for (size_t i = 1; i < size; i++) {
        if (*min > *pArr) {
            *min = *pArr;
        }
        if (*pArr > *max) {
            *max = *pArr;
        }

        pArr++;
    }
}

void updateAverage(int num1, int num2, float *avgVal) {
    *avgVal = (num1 + num2) / 2.0;
}

int main() {
    int myGrades[] = {80, 90, 100};
    int min, max;

    minMax(myGrades, 3, &min, &max);

    printf("The maximum value in the grades: %d\n", max);
    printf("The minimum value in the grades: %d\n", min);

    int valA, valB;
    float averageAB;

    printf("Enter the value var A: ");
    scanf("%d", &valA);

    printf("Enter the value var B: ");
    scanf("%d", &valB);

    updateAverage(valA, valB, &averageAB);
    printf("The average is: %.2lf", averageAB);

    return 0;
}