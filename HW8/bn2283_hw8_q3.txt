#include <iostream>
using namespace std;

// Function to reverse an array in-place
void reverseArray(int arr[], int arrSize) {
    int left = 0;
    int right = arrSize - 1;

    while (left < right) {
        // Swap elements at left and right positions
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        // Move the pointers toward the center
        left++;
        right--;
    }
}

// Function to remove odd numbers from an array
void removeOdd(int arr[], int& arrSize) {
    int evenCount = 0; // Initialize a counter for even numbers

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 == 0) {
            arr[evenCount] = arr[i]; // Copy even number to the front
            evenCount++;            // Increment the count of even numbers
        }
    }

    // Update the logical size of the array after removing odd numbers
    arrSize = evenCount;
}

// Function to swap two elements in an array
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to split odd and even numbers in an array
void splitParity(int arr[], int arrSize) {
    int left = 0; // Pointer to the leftmost element
    int right = arrSize - 1; // Pointer to the rightmost element

    while (left < right) {
        if (arr[left] % 2 == 0 && arr[right] % 2 != 0) {
            // Swap even and odd elements
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
        else {
            // Move the left pointer to the right if it's pointing to an odd number
            if (arr[left] % 2 != 0) {
                left++;
            }
            // Move the right pointer to the left if it's pointing to an even number
            if (arr[right] % 2 == 0) {
                right--;
            }
        }
    }
}

// Function to print the elements of an array
void printArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr1[10] = { 9, 2, 14, 12, -3 };
    int arr1Size = 5;

    int arr2[10] = { 21, 12, 6, 7, 14 };
    int arr2Size = 5;

    int arr3[10] = { 3, 6, 4, 1, 12 };
    int arr3Size = 5;

    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);

    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);

    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);

    return 0;
}
