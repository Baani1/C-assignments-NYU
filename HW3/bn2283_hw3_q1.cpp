#include <iostream>
using namespace std;

int main() {
    double item1Price, item2Price, basePrice, priceAfterDiscounts, totalPrice;
    char hasClubCard;
    double taxRate;

    // Input
    cout << "Enter price of first item: ";
    cin >> item1Price;

    cout << "Enter price of second item: ";
    cin >> item2Price;

    cout << "Does customer have a club card? (Y/N): ";
    cin >> hasClubCard;

    cout << "Enter tax rate, e.g., 5.5 for 5.5% tax: ";
    cin >> taxRate;

    // Calculate base price
    basePrice = item1Price + item2Price;

    // Calculate price after discounts
    double lowerPrice = (item1Price < item2Price) ? item1Price : item2Price;
    double discountPrice = lowerPrice / 2.0;

    if (hasClubCard == 'Y' || hasClubCard == 'y') {
        priceAfterDiscounts = basePrice - discountPrice;
        priceAfterDiscounts -= priceAfterDiscounts * 0.1; // Additional 10% off for club card members
    } else {
        priceAfterDiscounts = basePrice - discountPrice;
    }

    // Calculate total price after tax
    totalPrice = priceAfterDiscounts + (priceAfterDiscounts * taxRate / 100.0);

    // Output
    cout << "Base price: " << basePrice << endl;
    cout << "Price after discounts: " << priceAfterDiscounts << endl;
    cout << "Total price: " << totalPrice << endl;

    return 0;
}
