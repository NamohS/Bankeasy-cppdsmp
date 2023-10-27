#include <iostream>
#include <string>
using namespace std;
class Transaction {
public:
    double amount;
    string type;
    Transaction() : amount(0), type("") {} //default constructor
    Transaction(double amount, string type) : amount(amount), type(type) {} //parameterized constructor
};
class BankAccount {
public:
    string accountNumber;
    string accountHolderName;
    double balance;
    int transactionCount;
    Transaction transactions[100];//object initialisation in array
    BankAccount()//default constuctor
	 {
        accountNumber = "";
        accountHolderName = "";
        balance = 0.0;
        transactionCount = 0;
    }

    BankAccount(string accNumber, string accHolder, double initialBalance) //parameterized constructor
	{
        accountNumber = accNumber;
        accountHolderName = accHolder;
        balance = initialBalance;  }
    void deposit(double amount) {
        if (transactionCount < 100) {
            balance += amount;
            transactions[transactionCount] = Transaction(amount, "Deposit");
            transactionCount++;
        } else {
            cout << "Transaction history is full." << endl;        }    }
    void withdraw(double amount) {
        if (transactionCount < 100 && balance >= amount) {
            balance -= amount;
            transactions[transactionCount] = Transaction(amount, "Withdrawal");
            transactionCount++;
        } else {
            cout << "Insufficient funds or transaction history is full." << endl;        }  }
            
    double getBalance() { return balance; }
    string getAccountNumber()  { return accountNumber; }
    string getAccountHolderName(){ return accountHolderName; }
    
    void displayTransactionHistory() {
        cout << "Transaction History for Account Number " << accountNumber << ":" << endl;
        for (int i = 0; i < transactionCount; i++) {
            cout << "Transaction Type: " << transactions[i].type << ", Amount: $" << transactions[i].amount << endl;
        }    }};
        
void createAccount(BankAccount accounts[], int& accountCount, string accNumber, string accHolder, double initialBalance) {
    if (accountCount < 100) {
        accounts[accountCount] = BankAccount(accNumber, accHolder, initialBalance);
        accountCount++;
        cout << "Account created successfully." << endl<<endl;    } 
	else {cout << "Maximum account limit reached." << endl;    }
}
BankAccount* findAccount(BankAccount accounts[], int accountCount, string accNumber) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNumber) {
            return &accounts[i];        }    }
        return NULL;}

int main() {
    BankAccount accounts[100];
    int accountCount = 0;
    createAccount(accounts, accountCount, "12345", "prisha", 1000.0);//predefined accounts
    createAccount(accounts, accountCount, "67890", "namoh", 500.0);
    cout << "\033[2J\033[1;1H";//clear screen
    int choice;
    cout<<"WELCOME TO BANKEASY"<<endl<<endl;
    while (true) {
        cout << "Banking Menu:" << endl<<"1. Create Account" <<endl<< "2. Deposit" << endl<< "3. Withdraw" << endl<< "4. Check Balance" << endl<< "5. Transaction History" << endl<< "6. Exit" << endl<< "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1 :{string accNumber, accHolder;
                    double initialBalance;
                    cout << "Enter Account Number: ";
                    cin >> accNumber;
                    cout << "Enter Account Holder's First Name: ";
                    cin >> accHolder;
                    initialBalance=0;                    
                    createAccount(accounts, accountCount, accNumber, accHolder, initialBalance);
                } break;
            case 2:{string accNumberDeposit;
                    double depositAmount;
                    cout << "Enter Account Number: ";
                    cin >> accNumberDeposit;
                    BankAccount* accountDeposit = findAccount(accounts, accountCount, accNumberDeposit);
                    if (accountDeposit) {
                        cout << "Enter deposit amount: $";
                        cin >> depositAmount;
                        accountDeposit->deposit(depositAmount);
                         cout<<"Amount deposited successfully!"<<endl<<endl;
                    } 
					else {
                        cout << "Account not found." << endl;
                    } }   break;
            case 3:
                {   string accNumberWithdraw;
                    double withdrawAmount;
                    cout << "Enter Account Number: ";
                    cin >> accNumberWithdraw;
                    BankAccount* accountWithdraw = findAccount(accounts, accountCount, accNumberWithdraw);
                    if (accountWithdraw) {
                        cout << "Enter withdrawal amount: $";
                        cin >> withdrawAmount;
                        accountWithdraw->withdraw(withdrawAmount);
                        cout<<"Amount withdrawn successfully!";
                    } else {
                        cout << "Account not found." << endl;
                    }
                }
                cout<< endl;
                break;
            case 4:
                {
                    string accNumberBalance;
                    cout << "Enter Account Number: ";
                    cin >> accNumberBalance;
                    BankAccount* accountBalance = findAccount(accounts, accountCount, accNumberBalance);
                    if (accountBalance) {
                        cout << "Balance: $" << accountBalance->getBalance() << endl;
                    } else {
                        cout << "Account not found." << endl;
                    }
                }  break;
            case 5: {   string accNumberHistory;
                    cout << "Enter Account Number: ";
                    cin >> accNumberHistory;
                    BankAccount* accountHistory = findAccount(accounts, accountCount, accNumberHistory);
                    if (accountHistory) {
                        accountHistory->displayTransactionHistory();
                    } else {
                        cout << "Account not found." << endl;
                    }                }               
                break;
            case 6:               
                cout<<endl<<"THANK YOU FOR BANKING WITH US";
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl<<endl; }   
				 }   
				 return 0; }

