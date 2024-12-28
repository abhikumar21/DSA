#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 1. There are 3 strings, Original, Temp and Encrypted
    // i) transfer first char of original to end of temp
    // ii) transfer last char of temp to end of encrypted


void findEncryptedString(const string& original, string temp, string encrypted, int index, string& minEncrypted) {
    // Base case: If all characters have been moved to Encrypted
    if (index == original.size() && temp.empty()) {
        if (minEncrypted.empty() || encrypted < minEncrypted) {
            minEncrypted = encrypted;
        }
        return;
    }

    // Option 1: Move the first character of Original to Temp
    if (index < original.size()) {
        findEncryptedString(original, temp + original[index], encrypted, index + 1, minEncrypted);
    }

    // Option 2: Move the last character of Temp to Encrypted
    if (!temp.empty()) {
        findEncryptedString(original, temp.substr(0, temp.size() - 1), encrypted + temp.back(), index, minEncrypted);
    }
}

int main() {
    string original;
    cout << "Enter the Original string: ";
    cin >> original;

    string minEncrypted;
    findEncryptedString(original, "", "", 0, minEncrypted);
    cout << "Encrypted string with lowest lexicographical order: " << minEncrypted << endl;

    return 0;
}
