#include <stdio.h>
#include <stdlib.h>

typedef struct employee {
    char name[10];
    float age;
    int id;
} Employee;

Employee *createEmployees(int *size) {
    Employee *employeesArray;

    printf("Enter the total number of employees: ");
    scanf("%d", size);

    employeesArray = malloc(sizeof(Employee) * *size);

    return employeesArray;
}

void updateEmployees(Employee *arr, int size) {
    for (size_t i = 0; i < size; i++) {
        arr[i].id = i + 1;

        printf("Enter your name #%d: ", i + 1);
        scanf("%s", &arr[i].name);
        printf("Enter your age #%d: ", i + 1);
        scanf("%f", &arr[i].age);
    }
}

int main() {
    int totalEmployees;

    Employee *employeesArr = createEmployees(&totalEmployees);

    updateEmployees(employeesArr, totalEmployees);

    for (size_t i = 0; i < totalEmployees; i++) {
        printf("#%d. Name: %s, Age: %.2f\n", employeesArr[i].age, employeesArr[i].name, employeesArr[i].age);
    }
}