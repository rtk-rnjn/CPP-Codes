#include <iostream>
#include <stdlib.h>

using namespace std;

string center(const string s, const int w) {
    stringstream ss, spaces;
    int pad = w - s.size();
    // Pads the pad to the next pad
    for (int i = 0; i < pad / 2; ++i)
        spaces << " ";
    ss << spaces.str() << s << spaces.str();
    {
        // Pad pad to the end of the string
        if (pad > 0 && pad % 2 != 0)
            ss << " ";
    }
    return ss.str();
}

int displayFront()
{
    int choice;
    system("cls");
    cout << "+---------------------------------+" << endl;
    cout << "| Welcome to the login system     |" << endl;
    cout << "+---------------------------------+" << endl;
    cout << endl;
    cout << "+---------------------------------+" << endl;
    cout << "| 1. Login                        |" << endl;
    cout << "| 2. Register                     |" << endl;
    cout << "| 3. Exit                         |" << endl;
    cout << "+---------------------------------+" << endl;
    cout << endl;

    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int displayRegister()
{
    int choice;
    system("cls");
    cout << "+---------------------------------+" << endl;
    cout << "| Welcome to the register system  |" << endl;
    cout << "+---------------------------------+" << endl;
    cout << endl;
    cout << "+---------------------------------+" << endl;
    cout << "| 0. Register                     |" << endl;
    cout << "| 1. Back                         |" << endl;
    cout << "| 2. Exit                         |" << endl;
    cout << "+---------------------------------+" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int displayLogin()
{
    system("cls");
    int choice;
    cout << "+---------------------------------+" << endl;
    cout << "| Welcome to the login system     |" << endl;
    cout << "+---------------------------------+" << endl;
    cout << endl;
    cout << "+---------------------------------+" << endl;
    cout << "| 0. Login                        |" << endl;
    cout << "| 1. Back                         |" << endl;
    cout << "| 2. Exit                         |" << endl;
    cout << "+---------------------------------+" << endl;
    cout << endl;

    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

bool yesOrNo(string message)
{
    cout << endl;
    cout << "+---------------------------------+" << endl;
    cout << "| " << center(message, 31) << " |" << endl;
    cout << "| 1. Yes                          |" << endl;
    cout << "| 2. No                           |" << endl;
    cout << "+---------------------------------+" << endl;
    cout << endl;
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 1)
        return true;
    else
        return false;
}

void prompt(string message)
{
    cout << endl;
    cout << "+---------------------------------+" << endl;
    cout << "| " << center(message, 31) << " |" << endl;
    cout << "+---------------------------------+" << endl;
    cout << endl;
}
