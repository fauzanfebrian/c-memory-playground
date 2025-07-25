#include <stdio.h>

int main() {
    double grades[3] = {80.5, 90.3, 0};

    printf("grades start at %p\n", grades);

    printf("grades start -1 %p\n", grades - 1);

    printf("Array size of %d, because %d * %dbytes\n", sizeof(grades), sizeof(grades) / sizeof(grades[0]), sizeof(grades[0]));

    int grade2 = 10;
    printf("size of int+double = %d\n", sizeof(grades[0] + grade2));

    printf("size of float = %d\n", sizeof(float));
    printf("size of double = %d\n", sizeof(double));
    printf("size of int = %d\n", sizeof(int));
    printf("size of char = %d\n", sizeof(char));
    printf("size of \"a\" = %d\n", sizeof("a"));  // equals to: char temp[] = {'a', '\0'};
    printf("size of 'a' = %d\n", sizeof('a'));    // equals to: int temp = 97;

    int *ptr_grade2 = &grade2;
    double *ptr_grade = grades;

    printf("sizeof ptr grade2 %d\n", sizeof(ptr_grade2));  // i got 8 bytes because i use 64 bit environment
    printf("sizeof ptr grade %d\n", sizeof(ptr_grade));    // i got 8 bytes because i use 64 bit environment

    return 0;
}