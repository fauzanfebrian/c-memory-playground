#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int y;
} Point;

int main() {
    Point targetPoint, pointInFile;

    printf("What's the point you looking for:\n");
    printf("Enter X: ");
    scanf("%d", &targetPoint.x);
    printf("Enter Y: ");
    scanf("%d", &targetPoint.y);

    FILE* fp = fopen("./src/section-20/myFile3.bin", "rb");
    if (fp != NULL) {
        while (!feof(fp)) {
            fread(&pointInFile, sizeof(Point), 1, fp);
            if (pointInFile.x == targetPoint.x && pointInFile.y == targetPoint.y) {
                printf("Your point was found in the file!!\n");
                break;
            }
        }

        fclose(fp);
    }

    return 0;
}