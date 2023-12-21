#include <iostream>

using namespace std;

void printStars(int n) {
    if (n <= 0) {
        return;  // Base case: If n is less than or equal to 0, do nothing.
    }

    printStars(n - 1);  // Recursive call with n-1 to print the stars on the current line.
    cout << "*";        // Print a single asterisk.
}

void printTriangle(int n, int currentLine = 1) {
    if (currentLine > n) {
        return;  // Base case: If we've printed all lines, stop the recursion.
    }

    // Print the stars on the current line using the recursive function.
    printStars(currentLine);

    // Move to the next line by printing a newline character.
    cout << endl;

    // Recursively print the remaining lines.
    printTriangle(n, currentLine + 1);
}

 void printOppositeTriangles(int n) {
    if (n <= 0) {
        return;
    }

    // Print the first triangle
    for (int i = n-1; i >=0; i--) {
        for (int j = 0; j < i + 1; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // Print the second triangle
   for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << "*";
        }
        cout << endl;
    }

}

int main() {
    int n;
    cout << "Enter the number of lines for the triangle: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please provide a positive integer." << endl;
    } else {
       printOppositeTriangles(n);
    }

    return 0;
}
