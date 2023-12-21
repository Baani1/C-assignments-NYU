#include <iostream>
#include <string>
using namespace std;
int main() {
    // Read in two strings
    string str1, str2;
    cout << "Enter line1 " << endl;
    getline(cin, str1);
    cout << "Enter line2 " << endl;
    getline(cin, str2);
    // Convert the strings to lowercase and remove all punctuation and spaces
    for (int i = 0; i < str1.length(); i++) {
        if (!isalpha(str1[i])) {
            str1.erase(i, 1);
            i--;
        }
        else {
            str1[i] = tolower(str1[i]);
        }
    }
    for (int i = 0; i < str2.length(); i++) {
        if (!isalpha(str2[i])) {
            str2.erase(i, 1);
            i--;
        }
        else {
            str2[i] = tolower(str2[i]);
        }
    }
    // Sort the strings
    for (int i = 0; i < str1.length(); i++) {
        for (int j = i + 1; j < str1.length(); j++) {
            if (str1[i] > str1[j]) {
                char temp = str1[i];
                str1[i] = str1[j];
                str1[j] = temp;
            }
        }
    }
    for (int i = 0; i < str2.length(); i++) {
        for (int j = i + 1; j < str2.length(); j++) {
            if (str2[i] > str2[j]) {
                char temp = str2[i];
                str2[i] = str2[j];
                str2[j] = temp;
            }
        }
    }
    // Check if the strings are equal
    if (str1 == str2) {
        cout << "Yes, the strings are anagrams." << endl;
    }
    else {
        cout << "No, the strings are not anagrams." << endl;
    }
    return 0;
}