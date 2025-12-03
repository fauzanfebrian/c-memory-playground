#include <stdio.h>

/*
struct {
    type[member_name]: width;
};
*/

struct BitFieldExample {
    unsigned int field1 : 1;
    unsigned int field2 : 2;
    unsigned int field3 : 3;
};

int main() {
    struct BitFieldExample structExample;

    structExample.field1 = 1;
    structExample.field2 = 3;
    structExample.field3 = 5;

    printf("field1: %u, field2: %u, field3: %u", structExample.field1, structExample.field2, structExample.field3);
}