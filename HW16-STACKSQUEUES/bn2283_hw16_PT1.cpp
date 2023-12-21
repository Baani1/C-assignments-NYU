// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(ifstream& inputFile) 
{
    stack<char> symbols;
    char symbol;
    string word;
    bool hasBegin = false;

    while (inputFile >> word) {
        if (word == "begin") {
            hasBegin = true;
        }

        for (char c : word) {
            if (c == '{' || c == '(' || c == '[') {
                symbols.push(c);
            }
            else if (c == '}' || c == ')' || c == ']') {
                if (symbols.empty() || (!hasBegin && symbols.empty())) {
                    return false;
                }
                symbol = symbols.top();
                symbols.pop();
                if ((c == '}' && symbol != '{') ||
                    (c == ')' && symbol != '(') ||
                    (c == ']' && symbol != '[')) {
                    return false;
                }
            }
        }
    }
    return symbols.empty() && hasBegin;
}

int main() {
    ifstream inputFile("ba.txt"); // Provide the path to your input file here
    if (inputFile.is_open()) 
{
        if (isBalanced(inputFile)) {
            cout << "The symbols are balanced." << endl;
        }
        else {
            cout << "The symbols are not balanced." << endl;
        }
        inputFile.close();
    }
    else {
        cout << "Error: Unable to open the input file." << endl;
    }
    return 0;
}
