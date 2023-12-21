#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

class Friend {
public:
    string name;
    float amountPaid;
    float amountOwed;
    Friend* next;

    Friend(string n, float paid) : name(n), amountPaid(paid), amountOwed(0), next(nullptr) {}
};

class LinkedList {
private:
    Friend* head;

public:
    LinkedList() : head(nullptr) {}

    void insertFriend(string name, float amountPaid) {
        Friend* newFriend = new Friend(name, amountPaid);
        newFriend->next = head;
        head = newFriend;
    }

    Friend* getHead() const {
        return head;
    }

    ~LinkedList() {
        while (head != nullptr) {
            Friend* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

void readInputFile(string fileName, LinkedList& list) {
    ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            stringstream ss(line);
            float amountPaid;
            string name;
            ss >> amountPaid;
            getline(ss >> ws, name);  // Read the rest of the line as name
            list.insertFriend(name, amountPaid);
        }
        inputFile.close();
    } else {
        cout << "Error: Unable to open the file." << endl;
    }
}

void calculateBalances(LinkedList& list, float totalAmount, int numPeople) {
    float equalAmount = totalAmount / numPeople;
    Friend* currentFriend = list.getHead();
    while (currentFriend != nullptr) {
        currentFriend->amountOwed = equalAmount - currentFriend->amountPaid;
        currentFriend = currentFriend->next;
    }
}

void printInstructions(const LinkedList& list) {
    bool noTransactionsNeeded = true;
    Friend* currentFriend = list.getHead();
    while (currentFriend != nullptr) {
        if (currentFriend->amountOwed > 0.001) {
            noTransactionsNeeded = false;
            cout << currentFriend->name << ", you give ";
            Friend* creditor = list.getHead();
            bool firstCreditor = true;
            while (creditor != nullptr) {
                if (creditor->amountOwed < -0.001) {
                    if (!firstCreditor) {
                        cout << " and ";
                    }
                    cout << creditor->name << " $" << fixed << setprecision(6) << creditor->amountOwed;
                    currentFriend->amountOwed += creditor->amountOwed;
                    creditor->amountOwed = 0;
                    firstCreditor = false;
                }
                creditor = creditor->next;
            }
            cout << endl;
        }
        currentFriend = currentFriend->next;
    }

    if (noTransactionsNeeded) {
        cout << "In the end, you should all have spent around $" << fixed << setprecision(2) << list.getHead()->amountPaid << endl;
    }
}

int main() {
    string fileName;
    cout << "Enter the Filename: ";
    cin >> fileName;

    LinkedList friendsList;

    // Read input data from the file into the linked list
    readInputFile(fileName, friendsList);

    // Calculate balances
    float totalAmount = 0;
    int numPeople = 0;
    Friend* currentFriend = friendsList.getHead();
    while (currentFriend != nullptr) {
        totalAmount += currentFriend->amountPaid;
        numPeople++;
        currentFriend = currentFriend->next;
    }
    calculateBalances(friendsList, totalAmount, numPeople);

    // Print step-by-step reimbursement instructions
    printInstructions(friendsList);

    return 0;
}
