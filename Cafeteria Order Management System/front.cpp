#include <iostream>

#include <fstream>
#include <iomanip>

#include <json/json.h>
#include <stdlib.h>

using namespace std;

class Front
{
private:
    int totalItems = 0;
    double totalPrice = 0;

public:
    void __DISPLAY_ITEMS()
    {
        // Open the output file
        ifstream infile("output.json");

        if (!infile.is_open())
        {
            cout << "Error: Could not open output file" << endl;
            return;
        }

        // Parse the JSON data
        Json::Value root;
        infile >> root;

        if (!root.isArray())
        {
            cout << "Error: Invalid JSON data" << endl;
            return;
        }

        // Print out the items and their prices in a table format
        cout << setw(20) << left << "Item Name" << setw(10) << right << "Price" << endl;
        cout << setw(20) << left << "---------" << setw(10) << right << "-----" << endl;

        for (Json::Value::ArrayIndex i = 0; i < int(root.size()); i++)
        {
            Json::Value item = root[i];

            if (!item.isObject() || !item.isMember("item") || !item.isMember("price"))
            {
                cout << "Error: Invalid JSON data" << endl;
                return;
            }

            string itemName = item["item"].asString();
            double itemPrice = item["price"].asDouble();

            cout << setw(20) << left << itemName << setw(10) << right << fixed << setprecision(2) << itemPrice << endl;
        }

        // Close the file
        infile.close();
    }

    double __GET_ITEM_PRICE(string itemName)
    {
        ifstream infile("output.json");

        if (!infile.is_open())
        {
            cout << "Error: Could not open output file" << endl;
            return -1;
        }

        // Parse the JSON data
        Json::Value root;
        infile >> root;

        if (!root.isObject())
        {
            cout << "Error: Invalid JSON data" << endl;
            return -1;
        }

        for (Json::Value::ArrayIndex i = 0; i < int(root.size()); i++)
        {
            Json::Value item = root[i];
            if (!item.isObject() || !item.isMember("item") || !item.isMember("price"))
            {
                cout << "Error: Invalid JSON data" << endl;
                return -1;
            }
            string name = item["item"].asString();
            double price = item["price"].asDouble();
            if (name == itemName)
            {
                return price;
            }
        }

        return -1;
    }

    void __ADD_TO_CART(string itemName, int quantity)
    {
        totalPrice = totalPrice + (__GET_ITEM_PRICE(itemName) * quantity);
        totalItems = totalItems + quantity;
    }

    void __DISPLAY_INVOICE()
    {
        cout << "+----------------------------------------+" << endl;
        cout << "|                 INVOICE                |" << endl;
        cout << "+----------------------------------------+" << endl;
        cout << "| Total Items: " << totalItems << "            |" << endl;
        cout << "| Total Price: " << totalPrice << "            |" << endl;
        cout << "+----------------------------------------+" << endl;
    }

    string center(string s, int w) {
        return string((w - s.size()) / 2, ' ') + s;
    }

    void prompt(string s) {
        cout << "+----------------------------------------+" << endl;
        cout << "|" << center(s, 42) << "|" << endl;
        cout << "+----------------------------------------+" << endl;
    }

    int __MAIN_MENU() {
        cout << endl;
        cout << "+----------------------------------------+" << endl;
        cout << "|  1. Admin Login                        |" << endl;
        cout << "|  2. Continue to buy                    |" << endl;
        cout << "|  3. Exit                               |" << endl;
        cout << "+----------------------------------------+" << endl;

        int choice; cout << "Enter your choice: "; cin >> choice;
        return choice;
    }

    bool __ADMIN_LOGIN(string password)
    {
        if (password == "admin")
            return true;
        return false;
    }

    int __ADMIN_MENU()
    {
        cout << "+----------------------------------------+" << endl;
        cout << "|  1. Add Item                           |" << endl;
        cout << "|  2. Remove Item                        |" << endl;
        cout << "|  3. View Items                         |" << endl;
        cout << "|  4. Exit                               |" << endl;
        cout << "+----------------------------------------+" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        return choice;
    }

    void __CONTINUE_TO_BUY()
    {
        this->__DISPLAY_ITEMS();
        string itemName;
        cout << "Enter item name: ";
        cin >> itemName;

        int quantity;
        cout << "Enter quantity: ";
        cin >> quantity;

        this->__ADD_TO_CART(itemName, quantity);

        cout << "Add more items? (y/n): ";
        string choice;
        cin >> choice;
        if (choice == "y" || choice == "Y")
        {
            __CONTINUE_TO_BUY();
        }

        cout << "Proceed to checkout? (y/n): ";
        cin >> choice;
        if (choice == "y" || choice == "Y")
        {
            __DISPLAY_INVOICE();
        }

        return;
    }
};