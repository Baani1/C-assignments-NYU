#include <iostream>

using namespace std;

void printShiftedTriangle(int n, int m, char symbol) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m + n - i - 1; ++j) {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; ++j) {
            cout << symbol;
        }
        cout << endl;
    }
}

void printPineTree(int n, char symbol) {
    for (int i = 2; i <= n + 1; ++i) {
        printShiftedTriangle(i, n - i + 1, symbol);
    }
}

int main() {
    int numTriangles;
    char fillCharacter;

    cout << "Enter the number of triangles in the pine tree: ";
    cin >> numTriangles;

    cout << "Enter the character to fill the tree with: ";
    cin >> fillCharacter;

    printPineTree(numTriangles, fillCharacter);

    return 0;
}



























