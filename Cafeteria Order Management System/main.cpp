#include <iostream>

#include "front.cpp"
#include "admin.cpp"

using namespace std;

int main() {
    Front front;
    Admin admin("admin");

    int choice, adminChoice;
    bool login;
    string pass;

    while (1 == 1) {
        choice = front.__MAIN_MENU();
        if (choice == 3)
            break;
        else if (choice == 2)
            front.__CONTINUE_TO_BUY();
        else if (choice == 1) {
            cout << "Enter The Passowrd: " << endl;
            cin >> pass;
            login = front.__ADMIN_LOGIN(pass);

            if (login) {
                adminChoice = front.__ADMIN_MENU();
                if (adminChoice == 1)
                    admin.__ADMIN_ADD_ITEM();
                else if (adminChoice == 2)
                    admin.__ADMIN_REMOVE_ITEM();
                else if (adminChoice == 3)
                    front.__DISPLAY_ITEMS();
                else
                    break;
            }
        }
        else
            break;
    }

    cout << "THANK YOU FOR USING THE PROGRAM!";
    return 0;
}