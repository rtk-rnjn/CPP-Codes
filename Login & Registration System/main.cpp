#include <iostream>
#include <stdlib.h>

#include "login.cpp"
#include "register.cpp"
#include "display.cpp"

using namespace std;

int main()
{
    // clear the screen
    system("cls");

    string username, password;
    int loginResult, registerResult;
    bool loginStatus, wantToRegister, wantToLogin;
    Register *registerUser;

    goto MAIN_MENU;

MAIN_MENU:
    int choice = displayFront();

    switch (choice)
    {
    case 1:
        goto LOGIN_USER;
        break;
    case 2:
        goto REGISTER_USER;
        break;
    case 3:
        goto EXIT_THE_PROGRAM;
        break;
    default:
        prompt("Invalid choice!");
        exit(0);
        break;
    }

// This is the entry point for login. We need to know what the user wants
LOGIN_USER:
    loginResult = displayLogin();

    if (loginResult == 1)
        goto MAIN_MENU;
    else if (loginResult == 2)
        goto EXIT_THE_PROGRAM;
    else if (loginResult == 0)
        goto CONTINUE_LOGIN;
    else
        prompt("Invalid choice!");
    exit(0);

// Prompt the user for username and password. 
// This is a bit tricky because we don't want to register a user once they've logged in
CONTINUE_LOGIN:
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    loginStatus = login(username, password);
    if (!loginStatus)
    {
        prompt("Login failed!");
        wantToRegister = yesOrNo("Do you want to register?");
        if (wantToRegister)
            goto REGISTER_USER;
        else
            goto EXIT_THE_PROGRAM;
    }
    else
    {
        prompt("Login successful!");
        exit(0);
    }

REGISTER_USER:
    registerResult = displayRegister();
    if (registerResult == 1)
        goto MAIN_MENU;
    else if (registerResult == 2)
        goto EXIT_THE_PROGRAM;
    else if (registerResult == 0)
        goto CONTINUE_REGISTER;
    else
        prompt("Invalid choice!");
    exit(0);

CONTINUE_REGISTER:
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    registerUser = new Register(username, password);
    registerUser->registerUser();
    prompt("User registered successfully!");

    wantToLogin = yesOrNo("Do you want to login?");
    if (wantToLogin)
        goto LOGIN_USER;
    else
        goto EXIT_THE_PROGRAM;

EXIT_THE_PROGRAM:
    prompt("THANK YOU FOR USING OUR PROGRAM");
    exit(0);

    return 0;
}
