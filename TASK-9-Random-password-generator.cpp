#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

string generateRandomPassword(int length) {
    const string charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    string password;
    password.reserve(length);

    srand(time(0)); // Seed for random number generation

    for (int i = 0; i < length; ++i) {
        password += charset[rand() % charset.length()];
    }

    return password;
}

int main() {
    int length;

    cout << "Random Password Generator\n";
    cout << "Enter the length of the password: ";
    cin >> length;

    if (length <= 0) {
        cout << "Invalid length. Please enter a positive integer.\n";
        return 1;
    }

    string password = generateRandomPassword(length);
    cout << "Generated Password: " << password << endl;

    return 0;
}
