#include <iostream>
using namespace std;

int main() {

    int input;

    cout<<"Please inter a positive integer: "<<endl;
    cin>>input;
//upper triangle
     for(int i = 1; i <= input; i ++) 
     {
        for(int j = 1; j <= i; j++) 
        {
            cout<<" ";
        }
        
        for(int j = i; j <= input; j++) {
            cout<<"* ";
        }
        
        cout<<endl;
     }
     
//lower triangle     
    for(int i = 1; i <= input; i++) {

        for(int j = i; j <= input; j++) {
            cout<<" ";
        }
        
         for(int j = 1; j <= i; j++) {
            cout<<"* ";
        }
          
        
        cout<<endl;
    }

    return 0;
}