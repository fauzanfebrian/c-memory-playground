#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char charsArray[] = {'H', 'E', 'L', 'L', 'O'};

    char *tempPtr;
    tempPtr = charsArray;
    tempPtr[0] = 'G';

    printf("String printed from charsArray: %s \n", charsArray);
    printf("String printed from tempPtr: %s \n", tempPtr);

    char str[] = "Hello";
    char *str2 = "Hello";  // This will create two memory, first pointer to the variable, second pointer to the String arr --> the String memory location is on Read Only Memory

    printf("str before = %s\n", str);
    printf("str2 before = %s\n", str2);

    // this str will cause an error because the str is not pointer to a string like str2 does
    // str = "Good-Bye";
    // because str2 is Read Only, so we cant manipulate the str2 at certain index
    // str2[1] = 'E';
    // this Good-Bye works because the New memory is allocated and the pointer from str2 is changed to the new address
    str2 = "Good-Bye";

    printf("str after = %s\n", str);
    printf("str2 after = %s\n", str2);

    return 0;
}