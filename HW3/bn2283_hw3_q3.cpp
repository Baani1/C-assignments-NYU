|#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double a, b, c;
    double discriminant, resultOne, resultTwo;
    
    cout<<"Please enter a value for a: "<<endl;
    cin>>a;
    cout<<"Please enter a value for b: "<<endl;
    cin>>b;
    cout<<"Please enter a value for c: "<<endl;
    cin>>c;

    //Solving

    discriminant = pow(b, 2) - (4 * a * c);
    resultOne = (-b + sqrt(discriminant)) / (2 * a);
    resultTwo = (-b - sqrt(discriminant)) / (2 * a);

    //Determining solutions

    if(a == 0 && b == 0 && c == 0) {
        cout<<"Infinite number of solutions"<<endl;
    }
    else if(a == 0 && b == 0 && c != 0) {
        cout<<"No solution"<<endl;
    }
     else if(a != 0 && discriminant < 0) {
        cout<<"No real solutions"<<endl;
    }
    else if(a != 0 && discriminant == 0) {
        cout<<"One real solution: "<<resultOne<<endl;
    }
    else {
        cout<<"Two real solutions: "<<resultOne<<" and "<<resultTwo<<endl;
    }
   
    return 0;
}