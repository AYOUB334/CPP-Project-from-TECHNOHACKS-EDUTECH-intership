#include <iostream>
using namespace std;

// Function to perform addition
double add(double a, double b) {
    return a + b;
}

// Function to perform subtraction
double subtract(double a, double b) {
    return a - b;
}

// Function to perform multiplication
double multiply(double a, double b) {
    return a * b;
}

// Function to perform division
double divide(double a, double b) {
    if (b == 0) {
        cout << "Error: Division by zero\n";
        return 0;
    }
    return a / b;
}

int main() {
    char op;
    double num1, num2, result;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    switch(op) {
        case '+':
            result = add(num1, num2);
            cout << "Result: " << result << endl;
            break;
        case '-':
            result = subtract(num1, num2);
            cout << "Result: " << result << endl;
            break;
        case '*':
            result = multiply(num1, num2);
            cout << "Result: " << result << endl;
            break;
        case '/':
            result = divide(num1, num2);
            cout << "Result: " << result << endl;
            break;
        default:
            cout << "Error: Invalid operator\n";
    }

    return 0;
}