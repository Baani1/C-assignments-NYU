#include <iostream>

using namespace std;

int minInArray2(int arr[], int low, int high) {
    if (low == high) {
        return arr[low]; // Base case: If there's only one element in the range, it's the minimum.
    }

    int mid = (low + high) / 2;
    int leftMin = minInArray2(arr, low, mid); // Find the minimum in the left half.
    int rightMin = minInArray2(arr, mid + 1, high); // Find the minimum in the right half.
    
    // Compare the minimums from the left and right halves and return the smaller of the two.
    return (leftMin < rightMin) ? leftMin : rightMin;
}

int main() {
    int arr[10] = {9, -2, 14, 12, 3, 6, 2, 1, -9, 15};
    int res1, res2, res3, res4;
    res1 = minInArray1(arr, 10);
    res2 = minInArray2(arr, 0, 9);
    cout << res1 << " " << res2 << endl; // should both be -9
    res3 = minInArray2(arr, 2, 5);
    res4 = minInArray1(arr + 2, 4); // arr+2 is equivalent to &(arr[2])
    cout << res3 << " " << res4 << endl; // should both be 3
    return 0;
}
