#include <stdio.h>

typedef struct {
    unsigned int read : 1;
    unsigned int write : 1;
    unsigned int execute : 1;
} Permission;

void printPermission(Permission p) {
    printf("Permissions:\n");
    printf("Read:%u \n", p.read);
    printf("Write:%u \n", p.write);
    printf("Execute:%u \n", p.execute);
}

void changePermission(Permission* p, unsigned int newRead, unsigned int newWrite, unsigned int newExecute) {
    p->read = newRead;
    p->write = newWrite;
    p->execute = newExecute;
}

int main() {
    Permission p = {1, 1, 0};

    printPermission(p);

    changePermission(&p, p.read, 0, p.execute);
    printPermission(p);
}