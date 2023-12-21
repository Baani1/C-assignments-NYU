#include <iostream>
using namespace std;

bool hasMoreEvenDigits(int num) 
{
      int evenCount = 0, oddCount = 0;
   

      while (num > 0) 
        {
          int digit = num % 10;
            if (digit % 2 == 0)
            {
               evenCount++;
            }
           else 
            {
              oddCount++;
            }
        num /= 10;
    }

    return evenCount > oddCount;
}

int main () 
{
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    cout << "Numbers from 1 to " << n << " with more even digits than odd digits:" << endl;

    for (int num = 1; num <= n; num++) {
        if (hasMoreEvenDigits(num)) {
            cout << num << endl;
        }
    }

    return 0;
}
