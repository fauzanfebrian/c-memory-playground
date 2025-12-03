#include <stdio.h>

typedef struct ControlRegister {
    unsigned int enableDevice : 1;
    unsigned int resetDevice : 1;
    unsigned int interruptDevice : 1;
    unsigned int modeSelect : 2;
    unsigned int reserved : 27;
} ControlRegister;

int main() {
    ControlRegister controlReg = {0};

    controlReg.enableDevice = 1;
    controlReg.modeSelect = 3;

    printf("Size of control register %lu bytes\n", sizeof(controlReg));

    return 0;
}