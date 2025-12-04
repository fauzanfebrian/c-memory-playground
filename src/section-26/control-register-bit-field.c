#include <stdio.h>

typedef struct ControlRegister {
    unsigned int enableDevice : 1;     // Bit 0: Enable/Disable the device
    unsigned int resetDevice : 1;      // Bit 1: Reset the device
    unsigned int interruptDevice : 1;  // Bit 2: enable or disable interrupts
    unsigned int modeSelect : 2;       // Bits 3-4: select operating mode
    unsigned int enableTX : 1;         // Bit 5
    unsigned int enableRX : 1;         // Bit 6
    unsigned int reserved : 27;        // Bits 7-31: Reserved for future use
} ControlRegister;

int main() {
    ControlRegister controlReg = {0};

    controlReg.enableDevice = 1;
    controlReg.modeSelect = 3;

    printf("Size of control register %lu bytes\n", sizeof(controlReg));

    return 0;
}