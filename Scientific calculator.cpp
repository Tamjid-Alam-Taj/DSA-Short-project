#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

void displayMenu() {
    cout << "\n--- Scientific Calculator ---" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;
    cout << "5. Power (x^y)" << endl;
    cout << "6. Square Root (√x)" << endl;
    cout << "7. Logarithm (log base 10)" << endl;
    cout << "8. Natural Logarithm (ln)" << endl;
    cout << "9. Sine (sin)" << endl;
    cout << "10. Cosine (cos)" << endl;
    cout << "11. Tangent (tan)" << endl;
    cout << "12. Exit" << endl;
    cout << "Choose an operation: ";
}

void basicOperations(int choice) {
    double num1, num2, result;

    cout << "Enter first number: ";
    cin >> num1;

    if (choice >= 1 && choice <= 3) {
        cout << "Enter second number: ";
        cin >> num2;
    }

    switch (choice) {
        case 1:
            result = num1 + num2;
            cout << "Result: " << result << endl;
            break;
        case 2:
            result = num1 - num2;
            cout << "Result: " << result << endl;
            break;
        case 3:
            result = num1 * num2;
            cout << "Result: " << result << endl;
            break;
        case 4:
            if (num2 == 0) {
                cout << "Error: Division by zero!" << endl;
            } else {
                result = num1 / num2;
                cout << "Result: " << result << endl;
            }
            break;
    }
}

void scientificOperations(int choice) {
    double num, result;

    cout << "Enter the number: ";
    cin >> num;

    switch (choice) {
        case 5:
            double power;
            cout << "Enter the exponent: ";
            cin >> power;
            result = pow(num, power);
            cout << "Result: " << result << endl;
            break;
        case 6:
            if (num < 0) {
                cout << "Error: Square root of a negative number is undefined!" << endl;
            } else {
                result = sqrt(num);
                cout << "Result: " << result << endl;
            }
            break;
        case 7:
            if (num <= 0) {
                cout << "Error: Logarithm of a non-positive number is undefined!" << endl;
            } else {
                result = log10(num);
                cout << "Result: " << result << endl;
            }
            break;
        case 8:
            if (num <= 0) {
                cout << "Error: Natural logarithm of a non-positive number is undefined!" << endl;
            } else {
                result = log(num);
                cout << "Result: " << result << endl;
            }
            break;
        case 9:
            result = sin(num);
            cout << "Result (in radians): " << result << endl;
            break;
        case 10:
            result = cos(num);
            cout << "Result (in radians): " << result << endl;
            break;
        case 11:
            result = tan(num);
            cout << "Result (in radians): " << result << endl;
            break;
    }
}

int main() {
    int choice;

    do {
        displayMenu();
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input! Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice >= 1 && choice <= 4) {
            basicOperations(choice);
        } else if (choice >= 5 && choice <= 11) {
            scientificOperations(choice);
        } else if (choice == 12) {
            cout << "Exiting the calculator. Goodbye!" << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 12);

    return 0;
}
