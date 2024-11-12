#include <iostream>
#include <string>
using namespace std;

class GeneralizedCaesarCipher {
public:
    string encrypt(const string& text, int shift) {
        string encryptedText;
        for (char c : text) {
            char shifted = static_cast<char>((static_cast<unsigned char>(c) + shift) % 256);
            encryptedText += shifted;
        }
        return encryptedText;
    }

    string decrypt(const string& text, int shift) {
        string decryptedText;
        for (char c : text) {
            char shifted = static_cast<char>((static_cast<unsigned char>(c) - shift + 256) % 256);
            decryptedText += shifted;
        }
        return decryptedText;
    }
};

// int main() {
//     GeneralizedCaesarCipher cipher;
//     string text;
//     int shift;

//     cout << "Enter text to encrypt: ";
//     getline(cin, text);

//     cout << "Enter shift amount: ";
//     cin >> shift;

//     string encryptedText = cipher.encrypt(text, shift);
//     cout << "Encrypted text: " << encryptedText << endl;

//     string decryptedText = cipher.decrypt(encryptedText, shift);
//     cout << "Decrypted text: " << decryptedText << endl;

//     return 0;
// }
