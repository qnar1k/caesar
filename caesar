#include <iostream>
#include <cstring> 
using namespace std;

class Cipher {
private:
    int N;
    char* arr1;

public:
    Cipher(int alphabetSize = 26) : N(alphabetSize) {
        if (N <= 0) {
            cerr << "Invalid alphabet size; setting default size of 26." << endl;
            N = 26;
        }
        
        arr1 = new char[N];
        for (int i = 0; i < N; i++) {
            arr1[i] = 'a' + i;
        }
    }

    ~Cipher() {
        delete[] arr1;
    }

    int getAlphabetSize() const {
        return N;
    }

    void setAlphabetSize(int newSize) {
        if (newSize > 0) {
            delete[] arr1;
            N = newSize;
            arr1 = new char[N];
            for (int i = 0; i < N; i++) {
                arr1[i] = 'a' + i;
            }
        } else {
            cerr << "Invalid alphabet size, keeping the existing size of " << N << "." << endl;
        }
    }

    void encrypt(const char word[], char encryptedWord[], int key) const {
        int len = strlen(word);
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < N; j++) {
                if (word[i] == arr1[j]) {
                    encryptedWord[i] = arr1[(j + key) % N];
                    break;
                }
            }
        }
        encryptedWord[len] = '\0';
    }

    void decrypt(const char word[], char decryptedWord[], int key) const {
        int len = strlen(word);
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < N; j++) {
                if (word[i] == arr1[j]) {
                    decryptedWord[i] = arr1[(j - key + N) % N];
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

    cout << "Enter the key: ";
    int key;
    cin >> key;

    Cipher cipher;

    cout << "Enter a word to encrypt: ";
    cin >> word;
    cipher.encrypt(word, encryptedWord, key);
    cout << "Encrypted word: " << encryptedWord << endl;

    cout << "Enter encrypted word to decrypt: ";
    cin >> word;
    cipher.decrypt(word, decryptedWord, key);
    cout << "Decrypted word: " << decryptedWord << endl;

    return 0;
}
