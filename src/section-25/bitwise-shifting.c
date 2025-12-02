#include <stdio.h>

void printBits(char x) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
    }
    printf("\n");
}

int main() {
    char val = 0b10110010;

    printf("OG: ");
    printBits(val);

    printf("Shift 3 to left: ");
    printBits(val << 3);

    printf("Shift 3 to right: ");
    printBits(val >> 3);  // depends on the machine, some machine will fill "1" and some machine fill "0" to the bit got shifted
}