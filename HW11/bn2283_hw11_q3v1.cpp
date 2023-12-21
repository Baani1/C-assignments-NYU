#include <iostream>

using namespace std;

int minInArray1(int arr[], int arrSize) {
    if (arrSize == 1) {
        return arr[0]; // Base case: If there's only one element, it's the minimum.
    }

    int minRest = minInArray1(arr, arrSize - 1); // Recursive call to find the minimum of the rest of the array.
    
    // Compare the minimum of the rest with the current element and return the smaller of the two.
    return (arr[arrSize - 1] < minRest) ? arr[arrSize - 1] : minRest;
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
