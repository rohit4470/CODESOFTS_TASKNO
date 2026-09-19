#include <iostream>

using namespace std;

int main() {
    double num1, num2;
    char op;

    cout << "=======================================" << endl;
    cout << "          SIMPLE CALCULATOR            " << endl;
    cout << "=======================================" << endl;

    // Input first number
    cout << "Enter first number: ";
    cin >> num1;

    // Input operator
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    // Input second number
    cout << "Enter second number: ";
    cin >> num2;

    cout << "\n---------------------------------------" << endl;

    // Perform calculation based on operator
    switch (op) {
        case '+':
            cout << "Result: " << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
            break;
        case '-':
            cout << "Result: " << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
            break;
        case '*':
            cout << "Result: " << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Result: " << num1 << " / " << num2 << " = " << (num1 / num2) << endl;
            } else {
                cout << "Error: Division by zero is not allowed!" << endl;
            }
            break;
        default:
            cout << "Error: Invalid operator! Please use +, -, *, or /." << endl;
            break;
    }

    cout << "---------------------------------------" << endl;

    return 0;
}