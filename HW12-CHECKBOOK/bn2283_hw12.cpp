#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Money {
private:
    double amount;

public:
    Money(double a) : amount(a) {}
    double getAmount() const { return amount; }
};

class Check {
private:
    int number;
    Money amount;
    bool cashed;

public:
    Check(int num, double amt, bool isCashed) : number(num), amount(amt), cashed(isCashed) {}

    int getNumber() const { return number; }
    double getAmount() const { return amount.getAmount(); }
    bool isCashed() const { return cashed; }

    void display() const {
        cout << "Check #" << number << " - Amount: $" << amount.getAmount();
        if (cashed) {
            cout << " - Cashed";
        } else {
            cout << " - Not Cashed";
        }
        cout << endl;
    }
};

int main() {
    vector<Check> checks;
    vector<Money> deposits;

    // Read checks
    int numChecks;
    cout << "Enter the number of checks: ";
    cin >> numChecks;

    for (int i = 0; i < numChecks; ++i) {
        int number;
        double amount;
        bool cashed;

        cout << "Enter check number: ";
        cin >> number;
        cout << "Enter check amount: $";
        cin >> amount;
        cout << "Has the check been cashed? (1 for yes, 0 for no): ";
        cin >> cashed;

        checks.push_back(Check(number, amount, cashed));
    }

    // Read deposits
    int numDeposits;
    cout << "Enter the number of deposits: ";
    cin >> numDeposits;

    for (int i = 0; i < numDeposits; ++i) {
        double depositAmount;
        cout << "Enter deposit amount: $";
        cin >> depositAmount;
        deposits.push_back(Money(depositAmount));
    }

    // Calculate total of checks cashed and total of deposits
    double totalCashed = 0.0;
    double totalDeposits = 0.0;

    for (const auto& check : checks) {
        if (check.isCashed()) {
            totalCashed += check.getAmount();
        }
    }

    for (const auto& deposit : deposits) {
        totalDeposits += deposit.getAmount();
    }

    // Calculate new balance
    double oldBalance, newBalance;
    cout << "Enter old account balance: $";
    cin >> oldBalance;

    newBalance = oldBalance + totalDeposits - totalCashed;

    // Output results
    cout << "\nTotal of checks cashed: $" << totalCashed << endl;
    cout << "Total of deposits: $" << totalDeposits << endl;
    cout << "New account balance should be: $" << newBalance << endl;

    // Output checks cashed since last balance
    cout << "\nChecks cashed since last balance:\n";
    for (const auto& check : checks) {
        if (check.isCashed()) {
            check.display();
        }
    }

    // Output checks still not cashed
    cout << "\nChecks still not cashed:\n";
    vector<Check> notCashedChecks;
    for (const auto& check : checks) {
        if (!check.isCashed()) {
            notCashedChecks.push_back(check);
        }
    }

    // Sort checks by check number
    sort(notCashedChecks.begin(), notCashedChecks.end(), [](const Check& a, const Check& b) {
        return a.getNumber() < b.getNumber();
    });

    for (const auto& check : notCashedChecks) {
        check.display();
    }

    return 0;
}
