#include <stdio.h>
#include <stdlib.h>

short int getSignBitValue(int *num) {
    return (*num >> (sizeof(*num) * 8 - 1)) & 1;
}

void printBinaryRepresentation(int n) {
    if (n <= 1) {
        printf("%d", n);
        return;
    }

    printBinaryRepresentation(n / 2);
    printf("%d", n % 2);
}

int main() {
    int n = 989;

    printf("bit from %d: ", n);
    printBinaryRepresentation(n);

    return 0;
}
