#include <iostream>
using namespace std;

int fib(int n) {
    if (n <= 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
   
    int num;
    cout << "Plese enter a positive integer: ";
    cin >> num;

    int result = fib(num);
    cout <<  result << endl;

    return 0;

}