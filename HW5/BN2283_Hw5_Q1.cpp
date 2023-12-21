#include <iostream>

using namespace std;

int main() {
    int n;

    // Read the positive integer 'n' from the user
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input. Please enter a positive integer." << endl;
        return 1; // Exit with an error code
    }

    // Print the multiplication table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            // Calculate and print the product of i and j
            cout << i * j << '\t'; // Using a tab for spacing
        }
        cout << endl; 
    }

    return 0; // Exit successfully
}