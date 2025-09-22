#include <stdlib.h>
#include <stdio.h>

size_t strlen(char *str) {
    size_t size = 0;

    while (str[size] != '\0') {
        size++;
    }

    return size;
}

char *strcat(char *destStr, char *srcStr) {
    char *concatStr;

    size_t lengthDest, lengthSource;
    lengthDest = strlen(destStr);
    lengthSource = strlen(srcStr);

    concatStr = malloc(lengthDest + lengthSource + 1);

    for (size_t i = 0; i < lengthDest + lengthSource; i++) {
        concatStr[i] = i >= lengthDest ? srcStr[i - lengthDest] : destStr[i];
    }

    concatStr[lengthDest + lengthSource + 1] = '\0';

    return concatStr;
}

char *strcpy(char *destStr, char *srcStr) {
    size_t i = 0;
    while (srcStr[i] != '\0') {
        destStr[i] = srcStr[i];
        i++;
    }
    destStr[i] = '\0';

    return destStr;
}

int strcmp(char *str1, char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return *str1 > *str2 ? 1 : -1;
        }
        str1++;
        str2++;
    }

    if (*str1 == *str2) {
        return 0;
    }

    return *str1 > *str2 ? 1 : -1;
}

int main() {
    printf("Str length for \"Hello\": %d\n", strlen("Hello"));

    char strDestination[20] = "Hello";
    char strSource[] = "World!";

    printf("string after concatenation: %s\n", strcat(strDestination, strSource));

    char str1[5] = "Tech";
    char str2[10];
    strcpy(str2, str1);
    printf("str 1 = %s\n", str1);
    printf("str 2 = %s\n", str2);

    printf("str1 compare to str2 is %d\n", strcmp(str1, str2));
    printf("str1 compare to strDestination is %d", strcmp(str1, strDestination));

    return 0;
}