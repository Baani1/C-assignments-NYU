#include <iostream>
#include <string>

using namespace std;

int main() {
    // Read the input name
    cout << "Enter a name (First Middle Last or First M. Last): ";
    string input_name;
    getline(cin, input_name);

    // Initialize variables for first name, middle name/initial, and last name
    string first_name = "";
    string middle_name = "";
    string last_name = "";

    // Find the positions of spaces in the input
    size_t first_space = input_name.find(' ');
    size_t last_space = input_name.rfind(' ');

    if (first_space != string::npos && last_space != string::npos) {
        first_name = input_name.substr(0, first_space);
        last_name = input_name.substr(last_space + 1);
        middle_name = input_name.substr(first_space + 1, last_space - first_space - 1);

        // Check if the middle name/initial needs a period
        if (middle_name.length() == 1) {
            middle_name += ".";
        }
    }

    // Print the formatted name
    string formatted_name = last_name + ", " + first_name + " " + middle_name;
    cout << formatted_name << endl;

    return 0;
}
