#include <iostream>
#include <cstring> 
#include <stdexcept>

using namespace std;

#define N 26

class Cipher {
private:
    char arr1[N];
    int key; // Store the original key
    int effectiveKey; // Store the validated effective key

public:
    Cipher() : key(0), effectiveKey(0) {
        for (int i = 0; i < N; i++) {
            arr1[i] = 'a' + i;
        }
    }

    // Setter for key with validation
    void setKey(int k) {
        if (k < 0) {
            throw invalid_argument("Key must be a non-negative integer.");
        }
        key = k;
        effectiveKey = key % N; // Compute effective key
    }

    // Getter for the original key
    int getKey() const {
        return key;
    }

    // Getter for the effective key
    int getEffectiveKey() const {
        return effectiveKey; // Return effective key
    }

    void encrypt(const char word[], char encryptedWord[]) {
        int len = strlen(word);
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < N; j++) {
                if (word[i] == arr1[j]) {
                    encryptedWord[i] = arr1[(j + getEffectiveKey())]; // Use effective key without % N
                    break; 
                }
            }
        }
        encryptedWord[len] = '\0';
    }

    void decrypt(const char word[], char decryptedWord[]) {
        int len = strlen(word);
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < N; j++) {
                if (word[i] == arr1[j]) {
                    decryptedWord[i] = arr1[(j - getEffectiveKey() + N)]; // Use effective key without % N
                    break; 
                }
            }
        }
        decryptedWord[len] = '\0';
    }
};

int main() {
    char word[100];
    char encryptedWord[100];
    char decryptedWord[100];

    Cipher cipher;

    cout << "Enter the key: ";
    int key;
    cin >> key;

    try {
        cipher.setKey(key); // Set and validate the key

        cout << "Enter a word to encrypt: ";
        cin >> word;
        cipher.encrypt(word, encryptedWord);
        cout << "Encrypted word: " << encryptedWord << endl;

        cout << "Enter encrypted word to decrypt: ";
        cin >> word;
        cipher.decrypt(word, decryptedWord);
        cout << "Decrypted word: " << decryptedWord << endl;
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl; // Print error message if key is invalid
    }

    return 0;
}
