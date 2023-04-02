#include <iostream>
#include <map>
#include <string>

using namespace std;

string center(string s, int w)
{
    return string((w - s.size()) / 2, ' ') + s;
}


class Calander
{
private:
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year;
    bool isLeapYear;
    map<int, string> mDays = {{0, "Sunday"}, {1, "Monday"}, {2, "Tuesday"}, {3, "Wednesday"}, {4, "Thursday"}, {5, "Friday"}, {6, "Saturday"}};

public:
    Calander(bool isLeapYear, int year){
        if (isLeapYear)
        {
            days[1] = 29;
        }
        this->isLeapYear = isLeapYear;
        this->year = year;
    }
    string getMonth(int monthNumber)
    {
        string months[] = {
            "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        return months[monthNumber];
    }

    int getDayNumber(int year, int month, int day)
    {
        int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
        year -= month < 3;
        return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
    }

    string __INT_DAY_TO_MONTH(int num)
    {
        return mDays[num];
    }

    void display(int monthNumber);
    int getNumberOfDays(int monthNumber, bool isLeapYear);
};

void Calander::display(int monthNumber)
{
    cout << endl << endl;
    cout << center(getMonth(monthNumber), 36-1) << endl;
    cout << "  Sun  Mon  Tue  Wed  Thr  Fri  Sat" << endl;
    cout << "-----------------------------------" << endl;
}

int Calander::getNumberOfDays(int monthNumber, bool isLeapYear)
{
    int days[] = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear)
    {
        days[1] = 29;
    }
    return days[monthNumber];
}