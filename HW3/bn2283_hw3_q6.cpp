#include <iostream>
using namespace std;

int main() {
    const double RATE_WEEKDAY_DAYTIME = 0.40;
    const double RATE_WEEKDAY_EVENING = 0.25;
    const double RATE_WEEKEND = 0.15;

    string dayOfWeek;
    int startTime, callDuration;
    double callCost;

        cout << "Enter the day of the week (Mo, Tu, We, Th, Fr, Sa, Su): ";
    cin >> dayOfWeek;

    cout << "Enter the start time of the call (in 24-hour notation, e.g., 13:30): ";
    cin >> startTime;

    cout << "Enter the call duration (in minutes): ";
    cin >> callDuration;

    
    if (dayOfWeek == "Sa" || dayOfWeek == "Su") {
       
        callCost = callDuration * RATE_WEEKEND;
    } else {
       
        if (startTime >= 8 && startTime <= 18) {
            // Daytime call (between 8:00 A.M. and 6:00 P.M.)
            callCost = callDuration * RATE_WEEKDAY_DAYTIME;
        } else {
            
            callCost = callDuration * RATE_WEEKDAY_EVENING;
        }
    }

  
    cout << "The cost of the call is: $" << callCost << endl;

    return 0;
}
