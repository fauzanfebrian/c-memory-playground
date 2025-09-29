#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int y;
} Point;

int main() {
    Point pointsArray[5];

    int i;

    for (size_t i = 0; i < 5; i++) {
        printf("Enter #%d point 'x' coordinate: ", i + 1);
        scanf("%d", &pointsArray[i].x);
        printf("Enter #%d point 'y' coordinate: ", i + 1);
        scanf("%d", &pointsArray[i].y);
    }

    for (size_t i = 0; i < 5; i++) {
        printf("Point %d = (%d, %d)", i + 1, pointsArray[i].x, pointsArray[i].y);
    }
}