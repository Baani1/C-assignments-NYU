#include <iostream>
using namespace std;

int main() {
    const double POUNDS_TO_KG = 0.453592;
    const double INCHES_TO_METERS = 0.0254;

    double weightPounds, heightInches, bmi;

    
    cout << "Please enter weight (in pounds): ";
    cin >> weightPounds;

    cout << "Please enter height (in inches): ";
    cin >> heightInches;

    
    double weightKg = weightPounds * POUNDS_TO_KG;

    
    double heightMeters = heightInches * INCHES_TO_METERS;

  
    bmi = weightKg / (heightMeters * heightMeters);

    string weightStatus;

    if (bmi < 18.5) {
        weightStatus = "Underweight";
    } else if (bmi >= 18.5 && bmi < 25.0) {
        weightStatus = "Normal";
    } else if (bmi >= 25.0 && bmi < 30.0) {
        weightStatus = "Overweight";
    } else {
        weightStatus = "Obese";
    }

   
    cout << "The weight status is: " << weightStatus << endl;

    return 0;
}
