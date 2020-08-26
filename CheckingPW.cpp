#include <string>
#include <iostream>

using namespace std;

class Security
{
public:
    bool static checkPW(const string &userId, const string &password, const string &ciphertext)
    {
        string salt = userId;
        return generateCiphertext(salt + password) == ciphertext;
    }

    string static generateCiphertext(const string &plaintext)
    {
        return to_string(hash<string>{}(plaintext));
    }
};

int main(int argc, char **argv)
{
    // database
    string userId = "user001";
    string password = "passwordABC";
    string ciphertext = Security::generateCiphertext(userId + password);

    //
    if (Security::checkPW(userId, password, ciphertext))
    {
        cout << "Login successfully!" << endl;
    }
    else
    {
        cout << "Login failed." << endl;
    }
}