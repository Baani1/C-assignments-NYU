#include <iostream>

using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int printMonthCalendar(int numOfDays, int startingDay) {
    // Print header
    cout << "Mon\tTue\tWed\tThu\tFri\tSat\tSun" << endl;

    // Calculate spaces for alignment
    int currentDay = startingDay;
    for (int day = 1; day < startingDay; ++day) {
        cout << "\t";
    }

    for (int day = 1; day <= numOfDays; ++day) {
        cout << day << "\t";

        if (currentDay % 7 == 0) {
            cout << endl;
        }

        currentDay = (currentDay + 1) % 7;
    }
    cout << endl;

    return currentDay;
}

void printYearCalendar(int year, int startingDay) {
    const char* monthNames[12] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    for (int month = 1; month <= 12; ++month) {
        int daysInMonth;
        if (month == 2) {
            daysInMonth = isLeapYear(year) ? 29 : 28;
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            daysInMonth = 30;
        } else {
            daysInMonth = 31;
        }

        cout << monthNames[month - 1] << " " << year << endl;
        startingDay = printMonthCalendar(daysInMonth, startingDay);
        cout << endl;
    }
}

int main() {
    int year, startingDay;
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter starting day (1 for Mon, 2 for Tue, ..., 7 for Sun): ";
    cin >> startingDay;

    printYearCalendar(year, startingDay);

    return 0;
}
