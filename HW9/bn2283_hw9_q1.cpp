#include <iostream>
#include <string>
using namespace std;
int main() {
    string line;
    cout<< "Please eneter a line of text: ";
    getline(cin, line);

    // Count the number of words in the line
    int wordCount = 0;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ' ' || i == 0 ){
            wordCount++;
        }
    }
    // Count the number of occurrences of each letter
    int letterCount[26] = { 0 };
    for (int i = 0; i < line.length(); i++) {
        if (line[i] >= 'a' && line[i] <= 'z') {
            letterCount[line[i] - 'a']++;
        }
        else if (line[i] >= 'A' && line[i] <= 'Z') {
            letterCount[line[i] - 'A']++;
        }
    }
    // Output the number of words in the line
    cout << "Number of words: " << wordCount << " words" << endl;
    // Output the number of occurrences of each letter
    cout <<"lettercount: "<< endl;
    for (int i = 0; i < 26; i++) {
        if (letterCount[i] > 0) {
            cout << (char)(i + 'a') << ": " << letterCount[i] << endl;
        }
    }
    return 0;
}