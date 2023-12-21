#include <iostream>

using namespace std;

// Function to calculate the sum of squares of elements in an array
int sumOfSquares(int arr[], int arrSize) {
    // Base case: If the array is empty, the sum of squares is 0.
    if (arrSize == 0) {
        return 0;
    }
    
    // Calculate the square of the last element and add it to the sum of squares of the rest of the array.
    int lastElement = arr[arrSize - 1];
    return sumOfSquares(arr, arrSize - 1) + (lastElement * lastElement);
}

// Function to check if an array is sorted in ascending order
bool isSorted(int arr[], int arrSize) {
    // Base case: An empty array or an array with a single element is considered sorted.
    if (arrSize <= 1) {
        return true;
    }
    
    // Check if the last two elements are in ascending order, and recursively check the rest of the array.
    if (arr[arrSize - 1] < arr[arrSize - 2]) {
        return false;
    }
    
    return isSorted(arr, arrSize - 1);
}

int main() {
    int arr1[] = {2, -1, 3, 10};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    
    int arr2[] = {1, 2, 3, 4, 5};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int arr3[] = {5, 4, 3, 2, 1};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    
    cout << "Sum of squares for arr1: " << sumOfSquares(arr1, size1) << endl;
    cout << "Is arr2 sorted? " << (isSorted(arr2, size2) ? "Yes" : "No") << endl;
    cout << "Is arr3 sorted? " << (isSorted(arr3, size3) ? "Yes" : "No") << endl;
    
    return 0;
}
