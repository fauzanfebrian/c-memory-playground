#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int y;
} Point;

int main() {
    Point mPoint;
    int choice;

    printf("What's the point you would like to edit? (1-5)\n");
    printf("Enter: ");
    scanf("%d", &choice);

    FILE* fp = fopen("./src/section-20/myFile3.bin", "rb+");
    if (fp != NULL) {
        fseek(fp, (choice - 1) * sizeof(Point), SEEK_SET);
        printf("The point was located in the file...\n");

        printf("Enter new X: ");
        scanf("%d", &mPoint.x);
        printf("Enter new Y: ");
        scanf("%d", &mPoint.y);

        fwrite(&mPoint, sizeof(Point), 1, fp);
        fclose(fp);
    }

    return 0;
}