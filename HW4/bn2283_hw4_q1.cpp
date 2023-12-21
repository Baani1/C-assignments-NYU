#include <iostream>
using namespace std;

int main()
{
   int n;
   int loopCount = 1;
   int t = 2; // variable used in while loop
   int s = 2; // variable used in for loop
   
   cout<< "Please enter a positive integer: ";
   cin>> n;
     
   cout<< "section a: using while loop" <<endl;
     while(loopCount <= n)
        {
           cout<<t<< endl;
           t += 2;
           loopCount += 1;
        }
       
    cout<< "section b: using for loop" <<endl;
     for(loopCount=1; loopCount <= n; loopCount ++)
       {
           cout<<s<< endl;
           s += 2;
       }
    return 0;
}