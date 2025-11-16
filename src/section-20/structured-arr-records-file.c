#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int y;
} Point;

int main() {
    Point arrPoint[5] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};

    FILE* fp = fopen("./src/section-20/myFile3.bin", "wb");
    if (fp != NULL) {
        printf("File was successfully opened for binary writting\n");
        fwrite(arrPoint, sizeof(Point), 5, fp);
        fclose(fp);
    }

    return 0;
}