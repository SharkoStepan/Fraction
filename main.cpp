#include <iostream>
#include "Fraction.h"

using namespace std;

void showMenu() {
    cout << "Choose an operation:" << endl;
    cout << "1. Get numerator" << endl;
    cout << "2. Get denominator" << endl;
    cout << "3. Get whole part" << endl;
    cout << "4. Add two fractions" << endl;
    cout << "5. Subtract two fractions" << endl;
    cout << "6. Multiply two fractions" << endl;
    cout << "7. Divide two fractions" << endl;
    cout << "8. Prefix increment" << endl;
    cout << "9. Prefix decrement" << endl;
    cout << "10. Compare fractions" << endl;
    cout << "0. Exit the program" << endl;
}

int main() {
    int num1, denom1, num2, denom2;
    int choice; 

    cout << "Enter the first fraction (numerator and denominator): ";
    cin >> num1 >> denom1;
    Fraction f1(num1, denom1);

    cout << "Enter the second fraction (numerator and denominator): ";
    cin >> num2 >> denom2;
    Fraction f2(num2, denom2);

    while (true) {
        showMenu();
        cout << "Your choice: ";
        cin >> choice;

        if (choice == 0) {
            break; 
        }

        try {
            Fraction result;
            switch (choice) {
            case 1:
                cout << "Numerator of f1: " << f1.getNumerator() << endl;
                break;
            case 2:
                cout << "Denominator of f1: " << f1.getDenominator() << endl;
                break;
            case 3:
                cout << "Whole part of f1: " << f1.getWholePart() << endl;
                break;
            case 4:
                result = f1 + f2;
                cout << "Result of addition: " << result << endl;
                break;
            case 5:
                result = f1 - f2;
                cout << "Result of subtraction: " << result << endl;
                break;
            case 6:
                result = f1 * f2;
                cout << "Result of multiplication: " << result << endl;
                break;
            case 7:
                result = f1 / f2;
                cout << "Result of division: " << result << endl;
                break;
            case 8:
                cout << "f1 after prefix increment: " << ++f1 << endl;
                break;
            case 9:
                cout << "f1 after prefix decrement: " << --f1 << endl;
                break;
            case 10:
                if (f1 > f2) {
                    cout << "f1 is greater than f2" << endl;
                }
                else if (f1 < f2) {
                    cout << "f1 is less than f2" << endl;
                }
                else {
                    cout << "f1 is equal to f2" << endl;
                }
                break;
            default:
                cout << "Invalid choice!" << endl;
            }
        }
        catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    return 0;
}