#include <iostream>
#include "calander.cpp"

using namespace std;

int main()
{
    int year, days;
    cout << "Enter a year: ";
    cin >> year;

    // check if the year is leap year
    bool isLeapYear = false;

    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                isLeapYear = true;
            }
        }
        else {
            isLeapYear = true;
        }
    }

    Calander calander(isLeapYear, year);

    int current = calander.getDayNumber(year, 1, 1);

    for (int i = 0; i < 12; i++) {
        days = calander.getNumberOfDays(i, isLeapYear);

        // display header of a month
        calander.display(i);

        int k;
        // adding required space before the first day of the month
        for (k = 0; k < current; k++) {
            cout << "     ";
        }

        // adding number of days in a month
        for (int j = 1; j <= days; j++) {
            printf("%5d", j);
            
            // adding new line after every 7 days
            if (++k > 6) {
                k = 0;
                cout << endl;
            }
        }

        // check if new line is required
        if (k > 0) {
            cout << endl;
        }

        // set current day for the next month
        current = k;
    }

    return 0;
}