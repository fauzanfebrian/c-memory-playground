#include <stdio.h>

int main() {
    double grades[3] = {80.5, 90.3, 0};

    printf("grades start at %p\n", grades);

    printf("grades start -1 %p\n", grades - 1);

    return 0;
}