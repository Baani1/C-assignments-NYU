#include <iostream>
using namespace std;

int main() 
{
    int n, r;
    cout <<"Please enter a positive integer: ";
    cin >> n;

    // Handle the case of 0 input
    if (n == 0) {
        cout << "The Binary representation of 0 is 0" << endl;
        return 0;
    }
     
   cout << " The Binary representation of " << n << " is ";

    int binaryDigits = 0;

    // Count the number of binary digits
    int temp = n;
    while (temp > 0) 
    {
        temp /= 2;
        binaryDigits++;
    }

    // Print binary digits in correct order
    for (int i = binaryDigits - 1; i >= 0; i--) {
        r = (n >> i) & 1;
        cout <<r;
    }
        cout << endl;
    return 0;
}