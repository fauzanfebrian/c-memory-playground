#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int y;
} Point;

void printPoint(Point* point) {
    printf("Point = (%d, %d)", (*point).x, (*point).y);
}

int main() {
    Point* pointsArray;
    int totalPoints;

    printf("Enter the total number of points: ");
    scanf("%d", &totalPoints);

    pointsArray = malloc(sizeof(Point) * totalPoints);

    int i;
    for (size_t i = 0; i < totalPoints; i++) {
        printf("Enter #%d point 'x' coordinate: ", i + 1);
        scanf("%d", &pointsArray[i].x);
        printf("Enter #%d point 'y' coordinate: ", i + 1);
        scanf("%d", &pointsArray[i].y);
    }

    for (size_t i = 0; i < totalPoints; i++) {
        printPoint(&pointsArray[i]);
    }
}