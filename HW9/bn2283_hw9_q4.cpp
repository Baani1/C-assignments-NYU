// ConsoleApplication15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>

using namespace std;

// Function to reorder the elements as described
void oddsKeepEvensFlip(int arr[], int arrSize) {
    vector<int> odds;  // To store odd numbers
    vector<int> evens; // To store even numbers

    // Separate odd and even numbers into two vectors
    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] % 2 == 0) {
            evens.push_back(arr[i]);
        }
        else {
            odds.push_back(arr[i]);
        }
    }

    // Copy odd numbers back to the original array
    int index = 0;
    for (int odd : odds) {
        arr[index++] = odd;
    }

    // Copy even numbers (in reverse order) to the original array
    for (int i = evens.size() - 1; i >= 0; --i) {
        arr[index++] = evens[i];
    }
}

int main() {
    int arrSize;

    cout << "Enter the size of the array: ";
    cin >> arrSize;

    int* arr = new int[arrSize]; // Dynamically allocate memory for the array

    cout << "Enter " << arrSize << " integers separated by spaces: ";
    for (int i = 0; i < arrSize; ++i) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < arrSize; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    oddsKeepEvensFlip(arr, arrSize);

    cout << "Modified array: ";
    for (int i = 0; i < arrSize; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; // Deallocate the dynamically allocated memory

    return 0;
}
