#include <iostream>
#include <cmath>

using namespace std;

// Function to find proper divisors of a number and calculate their sum
int sumProperDivisors(int num) {
    int sum = 1; // Include 1 as a proper divisor
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i) {
                sum += num / i;
            }
        }
    }
    return sum;
}

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs) {
    outCountDivs = 0;
    outSumDivs = 0;

    for (int i = 1; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            outCountDivs++;
            outSumDivs += i;
            if (i != num / i) {
                outCountDivs++;
                outSumDivs += num / i;
            }
        }
    }

    // Subtract num itself as it's not a proper divisor
    outSumDivs -= num;
}

bool isPerfect(int num) {
    int countDivs, sumDivs;
    analyzeDivisors(num, countDivs, sumDivs);

    return sumDivs == num;
}

int main() {
    int M;
    cout << "Enter a positive integer M (>= 2): ";
    cin >> M;

    if (M < 2) {
        cout << "Please enter a valid number (>= 2)." << endl;
        return 1;
    }

    cout << "Perfect numbers between 2 and " << M << ":" << endl;
    for (int num = 2; num <= M; ++num) {
        if (isPerfect(num)) {
            cout << num << " ";
        }
    }
    cout << endl;

    cout << "Amicable number pairs between 2 and " << M << ":" << endl;
    for (int num1 = 2; num1 <= M; ++num1) {
        int num2 = sumProperDivisors(num1);

        if (num2 <= M && num1 != num2 && sumProperDivisors(num2) == num1) {
            cout << "(" << num1 << ", " << num2 << ")" << endl;
        }
    }

    return 0;
}
