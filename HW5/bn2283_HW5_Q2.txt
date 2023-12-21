#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int secretNumber = rand() % 100 + 1;
    int remainingGuesses = 5;
    int lowerBound = 1;
    int upperBound = 100;

    cout << "I thought of a number between 1 and 100! Try to guess it." << endl;

    while (remainingGuesses > 0) {
        cout << "Range: [" << lowerBound << ", " << upperBound << "], Number of guesses left: " << remainingGuesses << endl;

        int userGuess;
        cout << "Your guess: ";
        cin >> userGuess;

        if (userGuess == secretNumber) {
            cout << "Congrats! You guessed my number in " << 5 - remainingGuesses + 1 << " guesses." << endl;
            break;
        }
        else if (userGuess < secretNumber) {
            cout << "Wrong! My number is bigger." << endl;
            lowerBound = userGuess + 1;
        }
        else {
            cout << "Wrong! My number is smaller." << endl;
            upperBound = userGuess - 1;
        }

        --remainingGuesses;

        if (remainingGuesses == 0) {
            cout << "Sorry, you've run out of guesses. My number was: " << secretNumber << endl;
        }
    }

    return 0;
}