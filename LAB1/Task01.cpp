// Suppose you are developing a bank account management system, and you have defined the
// BankAccount class with the required constructors. You need to demonstrate the use of these
// constructors in various scenarios.
// 1. Default Constructor Usage: Create a default-initialized BankAccount object named
// account1. Print out the balance of account1.
// 2. Parameterized Constructor Usage: Create a BankAccount object named account2 with
// an initial balance of $1000. Print out the balance of account2.
// 3. Copy Constructor Usage: Using the account2 you created earlier, create a new
// BankAccount object named account3 using the copy constructor. Deduct $200 from
// account3 and print out its balance. Also, print out the balance of account2 to ensure it
// hasn't been affected by the transaction involving account3.
#include <iostream>
using namespace std;
class BankAccount {
private:
    int ID;
    string Name;
    float balance;

public:
    // Default
    BankAccount() {
        ID = 0;
        Name = "xyz";
        balance = 500.0;
    }

    // Parameterize
    BankAccount(int id, string name, float bal = 1000.0) {
        ID = id;
        Name = name;
        balance = bal;
    }

    // Copy
    BankAccount(const BankAccount& b) {
        ID = b.ID;
        Name = b.Name;
        balance = b.balance;
    }
    void deduct(float amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Ammount is more than your current balance..." << endl;
        }
    }
    void showBalance() {
        cout << "Account Holder: " << Name<<endl ;
     cout << "Balance: $" << balance << endl;
    }
};

int main() {
    BankAccount account1;
    cout << "Account1" << endl;
    account1.showBalance();
    BankAccount account2(1, "Manahil", 1000.0);
    cout << "\nAccount2" << endl;
    account2.showBalance();
    BankAccount account3(account2);
    account3.deduct(200); 
    cout << "\nAccount3" << endl;
    account3.showBalance();
    cout << "\nAccount2 after deducting the ammount from account 3" << endl;
    account2.showBalance();

    return 0;
}