#include <stdio.h>

typedef struct point {
    long x;
    long y;
} Point;

int main() {
    Point p = {3.0, 5.0};
    FILE* fp = fopen("./src/section-20/myFile.bin", "wb");
    if (fp != NULL) {
        printf("File was successfully opened for binary writting\n");
        fwrite(&p, sizeof(Point), 1, fp);
        fclose(fp);
    }
    return 0;
}