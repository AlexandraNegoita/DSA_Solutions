    #include <iostream>

using namespace std;

// Write a program in C++ in which you define a class named BankAccount (with the members name, address, IBAN, sum etc.)
// which contains the usual banking operations (deposit, withdraw, display balance, display owner).
// Test the class.

class BankAccount {
private:
    char* name;
    char* address;
    char* IBAN;
    double sum;
public:
    BankAccount(){}
    BankAccount(char* name, char* address, char* IBAN, double sum) {
        this->name = name;
        this->address = address;
        this->IBAN = IBAN;
        this->sum = sum;
    }

    void setName(char* name) {
        this->name = name;
    }
    char* getName() {
        return this->name;
    }

    void setAddress(char* address) {
        this->address = address;
    }
    char* getAddress() {
        return this->address;
    }

    void setIBAN(char* IBAN) {
        this->IBAN = IBAN;
    }
    char* getIBAN() {
        return this->IBAN;
    }

    void setSum(double sum) {
        this->sum = sum;
    }
    double getSum(){
        return this->sum;
    }

    void displayBalance() {
        cout << "\nYour current balance is: " << this->sum;
    }

    void displayOwner() {
        cout << "\nThe account owner is: \n\t" << this->name << "\n\tAddress: " << this->address;
    }

    void deposit(double amount) {
        this->sum += amount;
    }

    bool withdraw(double amount) {
        bool withdrawn;
       if(amount > this->sum) {
           cout << "Insufficient funds!";
           withdrawn = false;
       } else {
            this->sum -= amount;
            withdrawn = true;
       }
       return withdrawn;
    }

    void displayDetails() {
        cout << "Details about the account :";
        cout << "\nIBAN: " << this->IBAN;
        displayOwner();
        displayBalance();
        cout << "\n";
    }

    ~BankAccount () {}
};

int main()
{
    BankAccount account("Popescu Ionel", "Strada Florilor Nr. 2", "ROING839392919363", 2000.0);
    char choice;
    bool exit = false;
    cout << "Your account: "; account.displayDetails();
    while(!exit) {
        cout << "\nYou can choose to: \n\t1 - See details about the owner;"
                << "\n\t2 - See details about your balance;"
                << "\n\t3 - Withdraw money;"
                << "\n\t4 - Deposit money;"
                << "\n\t5 - Exit;\n";
        cin >> choice;
        switch(choice) {
            case '1': {
                account.displayOwner();
                break;
            }
            case '2': {
                account.displayBalance();
                break;
            }
            case '3': {
                double sum;
                cout << "Amount to withdraw: "; cin >> sum;
                if(account.withdraw(sum)) cout << "Money withdrawn!";
                break;
            }
            case '4': {
                double sum;
                cout << "Amount to deposit: "; cin >> sum;
                account.deposit(sum);
                cout << "Money deposited!";
                break;
            }
            case '5': {
                cout << "Exiting ...";
                exit = true;
            }
        }
    }
    return 0;
}
