#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Part A: Read the length of the sequence
    int length;
    cout << "Section A: Reading the length of the sequence" << endl;
    cout << "Please enter the length of the sequence: ";
    cin >> length;

    if (length <= 0) {
        cout << "Invalid sequence length." << endl;
        return 1;
    }

    double productA = 1.0;
    double numberA;

    cout << "Please enter your sequence for Section A:" << endl;
    for (int i = 0; i < length; i++) {
        cin >> numberA;
        if (numberA <= 0) {
            cout << "Invalid input. Positive numbers are expected." << endl;
            return 1;
        }
        productA *= numberA;
    }

    double geometricMeanA = pow(productA, 1.0 / length);
    cout << "The geometric mean for Section A is: " << geometricMeanA << endl;

    // Part B: Read numbers until -1 is entered
    double productB = 1.0;
    double numberB;
    int countB = 0;

    cout << "Section B: Reading numbers until -1 is entered" << endl;
    cout << "Please enter a non-empty sequence of positive integers for Section B, each one in a separate line. End your sequence by typing -1:" << endl;
    while (true) {
        cin >> numberB;
        if (numberB == -1) {
            break;
        }
        if (numberB <= 0) {
            cout << "Invalid input. Positive numbers are expected." << endl;
            return 1;
        }
        productB *= numberB;
        countB++;
    }

    if (countB == 0) {
        cout << "No numbers entered for Section B." << endl;
        return 1;
    }

    double geometricMeanB = pow(productB, 1.0 / countB);
    cout << "The geometric mean for Section B is: " << geometricMeanB << endl;

    return 0;
}
