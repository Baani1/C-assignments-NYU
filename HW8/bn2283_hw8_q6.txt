#include <iostream>
#include <string>

using namespace std;

// Function to replace digits within integers with 'x'
string replaceDigitsWithX(const string& input) {
    string output = "";
    string word = "";

    for (char c : input) {
        if (isalpha(c) || isspace(c)) {
            // If the character is a letter or space, append the current word
            if (!word.empty()) {
                output += word;
                word = "";
            }
            output += c;
        } else {
            word += 'x'; // Replace digits with 'x'
        }
    }

    // Append the last word if it's not empty
    if (!word.empty()) {
        output += word;
    }

    return output;
}

int main() {
    string input;

    cout << "Please enter a line of text: " << endl;
    getline(cin, input);

    string result = replaceDigitsWithX(input);

    cout << "Modified text: " << result << endl;

    return 0;
}
