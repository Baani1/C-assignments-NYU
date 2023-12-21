#include<iostream>
#include <vector>


using namespace std;

vector<int> findMaxAndMin(vector<int>& arr) {
    if (arr.size() == 1) //for one element
    {
        return { arr[0], arr[0] };
    }
    else if (arr.size() == 2) //for 2 elements
    {
        if (arr[0] > arr[1]) {
            return { arr[1], arr[0] };
        }
        else {
            return { arr[0], arr[1] };
        }
    }
    else {
        // split the input into two halves
        vector<int> left(arr.begin(), (arr.begin() + arr.size() / 2));
        vector<int> right((arr.begin() + arr.size() / 2), arr.end());

        // recursively find the maximum and minimum of each half
        vector<int> maxAndMinLeft = findMaxAndMin(left);
        vector<int> maxAndMinRight = findMaxAndMin(right);

        // return the maximum and minimum for the entire problem
        int maxVal = max(maxAndMinLeft[1], maxAndMinRight[1]);
        int minVal = min(maxAndMinLeft[0], maxAndMinRight[0]);

        return { minVal, maxVal };
    }
}
int main() {
    vector<int> arr = { 4,-1,-250,-6788,234,990,3,-23 };
    vector<int> maxAndMin = findMaxAndMin(arr);
    cout << "Min: " << maxAndMin[0] << ", Max: " << maxAndMin[1] << endl;
    return 0;
}