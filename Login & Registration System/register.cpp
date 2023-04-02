#include <iostream>
#include <fstream>
#include <filesystem>

class Register
{
private:
    std::string username;
    std::string password;

public:
    Register(std::string username, std::string password)
    {
        this->username = username;
        this->password = password;
    }

    void encryptPassword()
    {
        // the key for encryption is 3 that is added to ASCII value
        for (int i = 0; i < this->password.length(); i++)
            this->password[i] = this->password[i] + 3;
    }

    void registerUser()
    {
        // create folder of name `username` in data/
        std::filesystem::create_directory("data/" + this->username);

        // create file of name `password.txt` in data/username/
        // and write password in it
        std::ofstream file("data/" + this->username + "/password.txt");
        encryptPassword();

        file << this->password;
        file.close();
    }
};