#include <iostream>

using namespace std;

// Function to find the minimum value and its indices in the array
void findMinAndIndices(int arr[], int arrSize, int& minValue, int minIndices[], int& numIndices) {
    if (arrSize <= 0) {
        cerr << "Error: Empty array or invalid array size." << endl;
        return;
    }

    minValue = arr[0]; // Initialize minValue to the first element of the array.
    numIndices = 0;   // Initialize the number of indices to 0.

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] < minValue) {
            // Found a new minimum value, update minValue and reset numIndices.
            minValue = arr[i];
            numIndices = 0;
        }

        if (arr[i] == minValue) {
            // Add the current index to the list of minimum value indices.
            minIndices[numIndices] = i;
            numIndices++;
        }
    }
}

int main() {
    const int arrSize = 20;
    int arr[arrSize];

    cout << "Please enter 20 integers separated by a space:" << endl;

    for (int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }

    int minValue;
    int minIndices[arrSize]; // Assuming the maximum possible number of indices is the array size.
    int numIndices;

    findMinAndIndices(arr, arrSize, minValue, minIndices, numIndices);

    cout << "The minimum value is " << minValue << ", and it is located in the following indices:";
    for (int i = 0; i < numIndices; i++) {
        cout << " " << minIndices[i];
    }
    cout << endl;

    return 0;
}