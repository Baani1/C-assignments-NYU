#include <iostream>
using namespace std;
const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;
const double DECIMAL_Zero = 0.00;
const double DECIMAL_FIFTY = 0.50;
int main(){
    double realNumber;
    int roundingMethod;
//User input
    cout<<"Please enter a Real number: "<<endl;
    cin>>realNumber;

    cout<<"Choose your rounding method:"<<endl;
    cout<<"1. Floor round \n"
          "2. Ceiling round \n"
          "3. Round to the nearest whole number"<<endl;
    cin>>roundingMethod;
//3 Options of rounding type.
    switch (roundingMethod) {

        case FLOOR_ROUND:
            int roundedNumber;
            if (realNumber < 0){
                roundedNumber = (int)realNumber - 1;
                cout << roundedNumber << endl;
            } else{
                roundedNumber = (int)realNumber;
                cout<<roundedNumber<<endl;
            }

            break;

        case CEILING_ROUND:
            if (realNumber < 0){
                roundedNumber = 1 + (int)realNumber;
                cout << roundedNumber << endl;
            } else{
                roundedNumber = (1 + (int)realNumber);
                cout<<roundedNumber<<endl;
            }

            break;

        case ROUND:
            int intNumber;
            double decimalPart;

            if (realNumber < 0){
                intNumber = realNumber;
                decimalPart = realNumber + intNumber;
            }
            else{
                intNumber = realNumber;
                decimalPart = realNumber - intNumber;
            }

            if (decimalPart >= DECIMAL_FIFTY)
            {
                if (decimalPart >= DECIMAL_Zero){
                    int wholeNumber;
                    intNumber = realNumber;
                    roundedNumber = intNumber + 1;
                }
                else{

                    roundedNumber = intNumber - 1;
                    cout << roundedNumber << endl;
                }
            }
            else
            {
                roundedNumber = intNumber;
                cout<<roundedNumber<<endl;

            }
            break;
        default:{
            cout<<"Error. Please enter a valid option: 1, 2, or 3. \n";
        }


    }





    return 0;
}