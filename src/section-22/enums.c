#include <stdio.h>

enum workingDays {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY
};

enum months {
    JAN = 1,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
};

int main() {
    enum months month;

    int salaries[13] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120};

    char* monthNames[] = {
        "",
        "JAN",
        "FEB",
        "MAR",
        "APR",
        "MAY",
        "JUN",
        "JUL",
        "AUG",
        "SEP",
        "OCT",
        "NOV",
        "DEC"};

    for (month = JAN; month <= DEC; month++) {
        printf("%3s%10d\n", monthNames[month], salaries[month]);
    }
}