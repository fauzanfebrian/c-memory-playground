#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strConcat(char *originalStr) {
    size_t i;
    char *newStr;

    size_t lengthOG = strlen(originalStr);
    newStr = malloc(2 * lengthOG + 1);
    for (i = 0; i < lengthOG; i++) {
        newStr[i] = originalStr[i];
        newStr[lengthOG + i] = originalStr[i];
    }
    newStr[lengthOG + i] = '\0';

    return newStr;
}

int main() {
    printf("Str Concat: %s", strConcat("HEllo"));
    return 0;
}