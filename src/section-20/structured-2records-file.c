#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int y;
} Point;

int main() {
    Point p1, p2;

    printf("Enter x1: ");
    scanf("%d", &p1.x);
    printf("Enter y1: ");
    scanf("%d", &p1.y);

    printf("Enter x2: ");
    scanf("%d", &p2.x);
    printf("Enter y2: ");
    scanf("%d", &p2.y);

    FILE* fp = fopen("./src/section-20/myFile2.bin", "wb");
    if (fp != NULL) {
        printf("File was successfully opened for binary writting\n");
        fwrite(&p1, sizeof(Point), 1, fp);
        fwrite(&p2, sizeof(Point), 1, fp);
        fclose(fp);
    }

    return 0;
}