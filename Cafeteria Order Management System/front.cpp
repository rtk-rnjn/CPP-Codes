#include <iostream>

#include <fstream>
#include <iomanip>

#include <json/json.h>

using namespace std;

void displayItems() {
    // Open the output file
    ifstream infile("output.json");

    if (!infile.is_open()) {
        cout << "Error: Could not open output file" << endl;
        return;
    }

    // Parse the JSON data
    Json::Value root;
    infile >> root;

    if (!root.isArray()) {
        cout << "Error: Invalid JSON data" << endl;
        return;
    }

    // Print out the items and their prices in a table format
    cout << setw(20) << left << "Item Name" << setw(10) << right << "Price" << endl;
    cout << setw(20) << left << "---------" << setw(10) << right << "-----" << endl;

    for (Json::Value::ArrayIndex i = 0; i < root.size(); i++) {
        Json::Value item = root[i];

        if (!item.isObject() || !item.isMember("itemName") || !item.isMember("itemPrice")) {
            cout << "Error: Invalid JSON data" << endl;
            return;
        }

        string itemName = item["itemName"].asString();
        double itemPrice = item["itemPrice"].asDouble();

        cout << setw(20) << left << itemName << setw(10) << right << fixed << setprecision(2) << itemPrice << endl;
    }

    // Close the file
    infile.close();
}