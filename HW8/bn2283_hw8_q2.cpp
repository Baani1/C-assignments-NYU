#include <iostream>
using namespace std;

// Function to check if a string is a palindrome
bool isPalindrome(string str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    string input;

    cout << "Please enter a word: ";
    cin >> input;

    if (isPalindrome(input)) {
        cout << input << " is a palindrome." << endl;
    }
    else {
        cout << input << " is not a palindrome." << endl;
    }

    return 0;
}

