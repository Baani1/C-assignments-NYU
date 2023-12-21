#include <iostream>
#include <string>
using namespace std;
int main(){
    int current_Year;
    int graduation_Year;
    const int freshman = 4, sophomore = 3, junior = 2, senior = 1;
    string Name, status;
    //User input.
    cout<<"What is your name? : "<<endl;
    cin>>Name;

    cout<<"What is your graduation year?: "<<endl;
    cin>>graduation_Year;

    cout<<"What is the current year?: "<<endl;
    cin>>current_Year;
    //Output of choices from user input.
    if (graduation_Year == current_Year || graduation_Year < current_Year)
        cout<<Name<<" You are Graduated!"<<endl;
    else if ((graduation_Year - current_Year) == senior)
        cout<<Name<<" You are a senior!"<<endl;
    else if ((graduation_Year - current_Year) == junior)
        cout<<Name<<" You are a junior!"<<endl;
    else if ((graduation_Year - current_Year) == sophomore)
        cout<<Name<<" You are a sophomore!"<<endl;
    else if ((graduation_Year - current_Year) == freshman)
        cout<<Name<<" You are a freshman!"<<endl;
    else
        cout <<Name<< " You are not in college yet!" <<endl;


    return 0;
}