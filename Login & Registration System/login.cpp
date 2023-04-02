#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <filesystem>

namespace fs = std::filesystem;

bool exists(std::string username);

bool login(std::string username, std::string password)
{
    // check if username exists
    if (exists(username))
    {
        // check if password is correct
        std::ifstream file("data/" + username + "/password.txt");
        std::string encryptedPassword;
        getline(file, encryptedPassword);
        file.close();

        // decrypt password
        for (int i = 0; i < encryptedPassword.length(); i++)
            encryptedPassword[i] = encryptedPassword[i] - 3;

        if (encryptedPassword == password)
            return true;
        else
            return false;
    }
    else
        return false;
}

bool exists(std::string username)
{
    return fs::exists("data/" + username);
}