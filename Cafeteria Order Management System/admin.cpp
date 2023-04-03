#include <iostream>
#include <json/json.h>
#include <fstream>

using namespace std;

class Admin
{
private:
    bool canAccessClass = true;

public:
    Admin(string password)
    {
        if (password == "admin")
        { // password for now
            cout << "Welcome Admin" << endl;
        }
        else
        {
            cout << "Wrong Password" << endl;
            canAccessClass = false;
        }
    }
    bool addItem(string itemName, double itemPrice);
    bool delItem(string itemName);
};

bool Admin::addItem(string itemName, double itemPrice)
{
    // add item to items.json
    if (!canAccessClass)
    {
        return false;
    }

    Json::Value root;
    ifstream input("items.json");

    if (input.is_open())
    {
        input >> root;
    }

    // Create new JSON data to append to the file
    Json::Value data;
    data["name"] = itemName;
    data["price"] = itemPrice;

    // Add the new item and its price to the existing JSON array
    if (root.isObject())
    {
        Json::Value &items = root["items"];
        if (items.isArray())
        {
            items.append(data);
        }
        else
        {
            Json::Value array(Json::arrayValue);
            array.append(data);
            root["items"] = array;
        }
    }
    else
    {
        Json::Value object(Json::objectValue);
        Json::Value array(Json::arrayValue);
        array.append(data);
        object["items"] = array;
        root = object;
    }

    // Open the file in write mode and write the JSON data to it
    ofstream output("output.json");
    if (output.is_open())
    {
        Json::StreamWriterBuilder builder;
        builder["indentation"] = "\t";
        std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
        writer->write(root, &output);
        output.close();
    }
    else
    {
        cerr << "Failed to open file for writing." << std::endl;
        return false;
    }

    return true;
}

bool Admin::delItem(string itemName)
{
    // Read existing JSON data from the file, if any
    Json::Value root;
    ifstream input("output.json");
    if (input.is_open())
    {
        input >> root;
    }

    // Search for the item in the JSON array and remove it
    if (root.isObject())
    {
        Json::Value &items = root["items"];
        if (items.isArray())
        {
            for (int i = 0; i < items.size(); i++)
            {
                Json::Value &item = items[i];
                if (item["item"].asString() == itemName)
                {
                    items.removeIndex(i, &item);
                    break;
                }
            }
        }
    }

    // Open the file in write mode and write the updated JSON data to it
    ofstream output("output.json");
    if (output.is_open())
    {
        Json::StreamWriterBuilder builder;
        builder["indentation"] = "\t";
        unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
        writer->write(root, &output);
        output.close();
        return true;
    }
    else
    {
        cerr << "Failed to open file for writing." << endl;
        return false;
    }

    return false;
}
