#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int pos;
    FILE* fp = fopen("text.txt", "r");
    // pos = ftell(fp);
    // printf("Position in the file = %d\n", pos);
    // fgetc(fp);
    // pos = ftell(fp);
    // printf("Position in the file = %d\n", pos);
    // fgetc(fp);
    // pos = ftell(fp);
    // printf("Position in the file = %d\n", pos);
    // fgetc(fp);
    // fseek(fp, -5, SEEK_END);
    rewind(fp);
    fclose(fp);
}