#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int y;
} Point;

void multiplyPointBy3(char* filename, unsigned int choice) {
    Point mPoint;

    FILE* fp = fopen(filename, "rb+");
    if (fp != NULL) {
        fseek(fp, (choice - 1) * sizeof(Point), SEEK_SET);
        fread(&mPoint, sizeof(Point), 1, fp);

        printf("Multiplying %d,%d by 3 at location %d\n", mPoint.x, mPoint.y, choice);

        mPoint.x *= 3;
        mPoint.y *= 3;

        // fseek(fp, (choice - 1) * sizeof(Point), SEEK_SET);
        fseek(fp, (-1) * (int)sizeof(Point), SEEK_CUR);
        fwrite(&mPoint, sizeof(Point), 1, fp);
        fclose(fp);
    }
}

int main() {
    unsigned int choice;

    printf("What's the point you would like to edit? (1-5)\n");
    printf("Enter: ");
    scanf("%d", &choice);

    multiplyPointBy3("./src/section-20/myFile3.bin", choice);

    return 0;
}