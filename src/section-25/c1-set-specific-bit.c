#include <stdio.h>
#include <stdlib.h>

void printBits(char x) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
    }
    printf("\n");
}

int main() {
    // Value    10110101
    char value = 0b10110101;
    char mask = 0b01001001;

    printf("Result OR: ");
    printBits(value | mask);

    char setValue = 0b10110101;
    char setMask = 0b01111111;

    printf("Result set: ");
    printBits(setValue & setMask);

    char toggleValue = 0b10011010;
    char toggleMask = 0b01000000;

    printf("Result toggle: ");
    printBits(toggleValue ^ toggleMask);
}