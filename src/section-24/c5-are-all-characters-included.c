#include <stdio.h>
#include <stdlib.h>

int areAllLettersIncluded(char* seq1, int seq1Size, char* seq2, int seq2Size) {
    int* arrCount = calloc(sizeof(int), 26);
    size_t i;

    for (i = 0; i < seq1Size; i++) {
        if (seq1[i] >= 'A' && seq1[i] <= 'Z') {
            arrCount[(int)(seq1[i] - 'A')] = 1;
        } else if (seq1[i] >= 'a' && seq1[i] <= 'z') {
            arrCount[(int)(seq1[i] - 'a')] = 1;
        }
    }

    for (i = 0; i < seq2Size; i++) {
        if (seq2[i] >= 'A' && seq2[i] <= 'Z') {
            arrCount[(int)(seq2[i] - 'A')] = 0;
        } else if (seq2[i] >= 'a' && seq2[i] <= 'z') {
            arrCount[(int)(seq2[i] - 'a')] = 0;
        }
    }

    for (i = 0; i < 26; i++) {
        if (arrCount[i] == 1) {
            free(arrCount);
            return 0;
        }
    }

    free(arrCount);
    return 1;
}

int main() {
    char s1a[] = "abc";
    char s2a[] = "cbA";  // all present

    char s1b[] = "hello";
    char s2b[] = "ole";  // missing h

    char s1c[] = "Zz";
    char s2c[] = "z";  // Z also covered

    char s1d[] = "abcXYZ";
    char s2d[] = "zyxCAB";  // random order, still complete

    char s1e[] = "code";
    char s2e[] = "";  // empty, always fails

    char s1f[] = "";
    char s2f[] = "whatever";  // empty seq1 always passes

    char s1g[] = "AaBbCc";
    char s2g[] = "abc";  // all letters covered

    char s1h[] = "QWEr";
    char s2h[] = "qwe";  // r missing

    printf("Example 1: %d\n", areAllLettersIncluded(s1a, 3, s2a, 3));  // 1
    printf("Example 2: %d\n", areAllLettersIncluded(s1b, 5, s2b, 3));  // 0
    printf("Example 3: %d\n", areAllLettersIncluded(s1c, 2, s2c, 1));  // 1
    printf("Example 4: %d\n", areAllLettersIncluded(s1d, 6, s2d, 6));  // 1
    printf("Example 5: %d\n", areAllLettersIncluded(s1e, 4, s2e, 0));  // 0
    printf("Example 6: %d\n", areAllLettersIncluded(s1f, 0, s2f, 8));  // 1
    printf("Example 7: %d\n", areAllLettersIncluded(s1g, 6, s2g, 3));  // 1
    printf("Example 8: %d\n", areAllLettersIncluded(s1h, 4, s2h, 3));  // 0
}