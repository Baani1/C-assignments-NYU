#include <iostream>
using namespace std;

int main() {
    int decimalNumber;
    
    cout << "Enter a decimal number: " << endl;
    cin >> decimalNumber;
   //The range limitation to 1-3999 ensures that the Roman numeral representation can be accurately calculated and presented using the basic symbols without additional conventions.
    if (decimalNumber < 1 || decimalNumber > 3999) {
        cout << "Invalid input. Please enter a number between 1 and 3999." << endl;
        return 1;
    }

    // Define decimalToRoman function inside the main code body
   
    auto decimalToRoman = [](int num)
    {
     
        while (num > 0) {
            if (num >= 1000) {
                cout << "M";
                num -= 1000;
            }  else if (num >= 500) {
                cout << "D";
                num -= 500;
            }  else if (num >= 100) {
                cout << "C";
                num -= 100;
            }  else if (num >= 50) {
                cout << "L";
                num -= 50;
            }  else if (num >= 10) {
                cout << "X";
                num -= 10;
            }  else if (num >= 5) {
                cout << "V";
                num -= 5;
            } else {
                cout << "I";
                num -= 1;
            }
           
            
        }
    };

    cout << decimalNumber << " is "  ;
     decimalToRoman(decimalNumber);
    cout << endl;

    return 0;
}
