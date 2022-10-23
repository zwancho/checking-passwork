#include <string>
#include <iostream>

class Security
{
public:
    bool static CheckPW(const std::string &userid, const std::string &password, const std::string &ciphertext)
    {
        std::string salt = userid;
        return GenerateCiphertext(salt + password) == ciphertext;
    }

    std::string static GenerateCiphertext(const std::string &plaintext)
    {
        return std::to_string(hash<std::string>{}(plaintext));
    }
};

int main(int argc, char **argv)
{
    // database
    std::string userid = "user001";
    std::string password = "passwordABC";
    std::string ciphertext = Security::GenerateCiphertext(userid + password);

    //
    if (Security::CheckPW(userid, password, ciphertext))
    {
        cout << "Login successfully!" << endl;
    }
    else
    {
        cout << "Login failed." << endl;
    }
}