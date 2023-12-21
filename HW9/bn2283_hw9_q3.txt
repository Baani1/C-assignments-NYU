// ConsoleApplication16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

// Function to count positive numbers in the array
int countPositives(int* arr, int arrSize) {
    int count = 0;
    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] > 0) {
            count++;
        }
    }
    return count;
}

// Version 1: Returns a new array and updates outPosArrSize
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    int numPositives = countPositives(arr, arrSize);
    int* posArr = new int[numPositives];
    int index = 0;
    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] > 0) {
            posArr[index++] = arr[i];
        }
    }
    outPosArrSize = numPositives;
    return posArr;
}

// Version 2: Returns a new array and uses outPosArrSizePtr to update size
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
    int numPositives = countPositives(arr, arrSize);
    int* posArr = new int[numPositives];
    int index = 0;
    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] > 0) {
            posArr[index++] = arr[i];
        }
    }
    *outPosArrSizePtr = numPositives;
    return posArr;
}

// Version 3: Updates outPosArr and outPosArrSize
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    int numPositives = countPositives(arr, arrSize);
    outPosArr = new int[numPositives];
    int index = 0;
    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] > 0) {
            outPosArr[index++] = arr[i];
        }
    }
    outPosArrSize = numPositives;
}

// Version 4: Uses outPosArrPtr and outPosArrSizePtr to update values
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    int numPositives = countPositives(arr, arrSize);
    *outPosArrPtr = new int[numPositives];
    int index = 0;
    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] > 0) {
            (*outPosArrPtr)[index++] = arr[i];
        }
    }
    *outPosArrSizePtr = numPositives;
}

int main()
{
    int arrSize;

    cout << "Enter the size of the array: ";
    cin >> arrSize;
    int* arr = new int[arrSize]; // Dynamically allocate memory for the array

    cout << "Enter " << arrSize << " integers separated by spaces: ";
    for (int i = 0; i < arrSize; ++i) {
        cin >> arr[i];
    }

    // Version 1
    int posArrSize1;
    int* posArr1 = getPosNums1(arr, arrSize, posArrSize1);
    cout << "Version 1 - Positive Numbers: ";
    for (int i = 0; i < posArrSize1; ++i) {
        cout << posArr1[i] << " ";
    }
    cout << endl;
    delete[] posArr1;

    // Version 2
    int posArrSize2;
    int* posArr2 = getPosNums2(arr, arrSize, &posArrSize2);
    cout << "Version 2 - Positive Numbers: ";
    for (int i = 0; i < posArrSize2; ++i) {
        cout << posArr2[i] << " ";
    }
    cout << endl;
    delete[] posArr2;

    // Version 3
    int* posArr3;
    int posArrSize3;
    getPosNums3(arr, arrSize, posArr3, posArrSize3);
    cout << "Version 3 - Positive Numbers: ";
    for (int i = 0; i < posArrSize3; ++i) {
        cout << posArr3[i] << " ";
    }
    cout << endl;
    delete[] posArr3;

    // Version 4
    int* posArr4;
    int posArrSize4;
    getPosNums4(arr, arrSize, &posArr4, &posArrSize4);
    cout << "Version 4 - Positive Numbers: ";
    for (int i = 0; i < posArrSize4; ++i) {
        cout << posArr4[i] << " ";
        cout << "Version 4 - Positive Numbers: ";
        for (int i = 0; i < posArrSize4; ++i) {
            cout << posArr4[i] << " ";
        }
        cout << endl;
        delete[] posArr4;

        return 0;
    }
}