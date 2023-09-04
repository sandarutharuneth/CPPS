#include <iostream>
#include <random>
#include <string>
#include <ctime>

using namespace std;

// Function to generate a random password
string generatePassword(int length, bool useNumbers, bool useSpecialChars, bool useUppercase, bool useLowercase) {
    string password;
    string uppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
    string numbers = "0123456789";
    string specialChars = "!@#$%^&*()-_+=<>?";

    string allChars = "";

    if (useUppercase)
        allChars += uppercaseChars;
    if (useLowercase)
        allChars += lowercaseChars;
    if (useNumbers)
        allChars += numbers;
    if (useSpecialChars)
        allChars += specialChars;

    if (allChars.empty()) {
        cout << "Please select at least one character type.\n";
        return "";
    }

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(0, allChars.size() - 1);

    for (int i = 0; i < length; ++i) {
        int randomIndex = distribution(generator);
        password += allChars[randomIndex];
    }

    return password;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int length;
    bool useNumbers, useSpecialChars, useUppercase, useLowercase;

    cout << "Password Length: ";
    cin >> length;

    cout << "Include numbers (1/0): ";
    cin >> useNumbers;

    cout << "Include special characters (1/0): ";
    cin >> useSpecialChars;

    cout << "Include uppercase letters (1/0): ";
    cin >> useUppercase;

    cout << "Include lowercase letters (1/0): ";
    cin >> useLowercase;

    string password = generatePassword(length, useNumbers, useSpecialChars, useUppercase, useLowercase);

    if (!password.empty()) {
        cout << "Generated Password: " << password << endl;
    }

    return 0;
}
