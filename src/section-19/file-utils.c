#include <stdio.h>
#include <stdlib.h>

int main() {
    int result;
    result = rename("./src/section-19/oldMyFile.txt", "./src/section-19/myFile.txt");
    if (result != 0) {
        printf("Error occured while tring to rename the file\n");
    } else {
        printf("File has been successfully renamed\n");
    }
    result = remove("./src/section-19/myFile.txt");
    if (result != 0) {
        printf("Error occured while tring to remove the file\n");
    } else {
        printf("File has been successfully removed\n");
    }
    return 0;
}