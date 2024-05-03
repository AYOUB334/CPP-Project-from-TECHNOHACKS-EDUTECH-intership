#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int binaryToDecimal(string binary) {
    int decimal = 0;
    int power = 0;

    // Iterate through the binary string from right to left
    for (int i = binary.length() - 1; i >= 0; --i) {
        if (binary[i] == '1') {
            // If the current digit is '1', add 2^power to the decimal value
            decimal += pow(2, power);
        }
        // Increment power for the next digit
        power++;
    }

    return decimal;
}

int main() {
    string binary;

    cout << "Binary to Decimal Converter\n";
    cout << "Enter a binary number: ";
    cin >> binary;

    // Validate binary input
    for (char digit : binary) {
        if (digit != '0' && digit != '1') {
            cout << "Invalid binary number.\n";
            return 1;
        }
    }

    int decimal = binaryToDecimal(binary);
    cout << "Decimal equivalent: " << decimal << endl;

    return 0;
}
