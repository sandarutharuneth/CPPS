#include <iostream>
#include <cmath>
using namespace std;

int main() {
    char operation;
    double num1, num2, result;

    cout << "Welcome to the Advanced Calculator!" << endl;
    cout << "Available operations:" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;
    cout << "5. Square Root (sqrt)" << endl;
    cout << "6. Exponentiation (x^y)" << endl;

    cout << "Enter the desired operation number: ";
    cin >> operation;

    switch (operation) {
        case '1':
            cout << "Enter two numbers to add: ";
            cin >> num1 >> num2;
            result = num1 + num2;
            cout << "Result: " << result << endl;
            break;
        case '2':
            cout << "Enter two numbers to subtract: ";
            cin >> num1 >> num2;
            result = num1 - num2;
            cout << "Result: " << result << endl;
            break;
        case '3':
            cout << "Enter two numbers to multiply: ";
            cin >> num1 >> num2;
            result = num1 * num2;
            cout << "Result: " << result << endl;
            break;
        case '4':
            cout << "Enter two numbers to divide: ";
            cin >> num1 >> num2;
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << result << endl;
            } else {
                cout << "Error: Division by zero is not allowed!" << endl;
            }
            break;
        case '5':
            cout << "Enter a number to find its square root: ";
            cin >> num1;
            if (num1 >= 0) {
                result = sqrt(num1);
                cout << "Square Root: " << result << endl;
            } else {
                cout << "Error: Square root of a negative number is undefined!" << endl;
            }
            break;
        case '6':
            cout << "Enter base (x) and exponent (y) for x^y: ";
            cin >> num1 >> num2;
            result = pow(num1, num2);
            cout << "Result: " << result << endl;
            break;
        default:
            cout << "Invalid operation selected!" << endl;
    }

    return 0;
}
