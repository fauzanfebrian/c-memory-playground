#include <stdio.h>

int main() {
    char x = 5;
    char y = 7;

    char output1 = ~x;
    char output2 = x & y;
    char output3 = x | y;
    char output4 = x ^ y;

    printf("Output 1: %d\n", output1);
    printf("Output 2: %d\n", output2);
    printf("Output 3: %d\n", output3);
    printf("Output 4: %d\n", output4);
}