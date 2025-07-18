#include<bits/stdc++.h>
using namespace std;
class Account{
private:
    string accountNumber;
    string name;
    string pin;
    double balance;

public:
    Account():accountNumber(""),name(""),pin(""),balance(0.0){}
    Account(string accNumber,string accName,double initialBalance,string accPin): accountNumber(accNumber),
    name(accName),balance(initialBalance),pin(accPin){}

    bool verifyPin(const string& enteredPin)const{
        return pin==enteredPin;
    }

    double getBalance()const{
        return balance;
    }

    string getAccountNumber()const{
        return accountNumber;
    }

    string getName()const{
        return name;
    }

    void deposit(double amount){
        if (amount<=0){
            cout<<"Invalid Deposit Amount.Please enter a positive amount.\n";
            return;
        }
        balance+=amount;
        cout<<"Deposit Successful!Current Balance:"<<balance<<endl;
    }

    bool withdraw(double amount){
        if(amount<=0){
            cout<<"Invalid Withdrawal Amount.Please enter a positive amount.\n";
            return false;
        }
        if(amount>balance){
            cout<<"Insufficient Balance.Withdrawal Failed.\n";
            return false;
        }
        balance-=amount;
        cout<<"Withdrawal Successful!Current Balance:"<<balance<<endl;
        return true;
    }
};
class Bank{
private:
    unordered_map<string,Account>accounts;

    bool verifyAccountPin(const string& accNumber){
        if (accounts.find(accNumber)==accounts.end()){
            cout<<"Account could not be found!\n";
            return false;
        }
        string enteredPin;
        cout<<"Enter PIN: ";
        cin>>enteredPin;
        if(accounts[accNumber].verifyPin(enteredPin)){
            return true;
        }
        cout<<"Incorrect PIN.Operation Denied.\n";
        return false;
    }

public:
    void createAccount(const string& accNumber,const string& accName,const string& accPin,double initialDeposit){
        if(accounts.find(accNumber)!=accounts.end()){
            cout<<"Account already exists with Account Number "<<accNumber<<endl;
            return;
        }
        if(accPin.length()!= 4||!isdigit(accPin[0])||!isdigit(accPin[1])||!isdigit(accPin[2])||!isdigit(accPin[3])) {
            cout<<"Invalid PIN!Please enter a 4-digit numeric PIN.\n";
            return;
        }
        if(initialDeposit<0){
            cout<<"Invalid Initial Deposit Amount.It cannot be negative.\n";
            return;
        }
        accounts[accNumber]=Account(accNumber,accName,initialDeposit,accPin);
        cout<<"Account created successfully for "<<accName<<" with Account Number:"<<accNumber<<endl;
    }

    void deposit(const string& accNumber,double amount){
        if(accounts.find(accNumber)==accounts.end()){
            cout<<"Account not found!\n";
            return;
        }
        if(verifyAccountPin(accNumber)){
            accounts[accNumber].deposit(amount);
        }
    }

    void withdraw(const string& accNumber,double amount){
        if(accounts.find(accNumber)==accounts.end()){
            cout<<"Account not found!\n";
            return;
        }
        if(verifyAccountPin(accNumber)){
            accounts[accNumber].withdraw(amount);
        }
    }

    void transfer(const string& fromAcc,const string& toAcc,double amount){
        if(accounts.find(fromAcc)==accounts.end()){
            cout<<"Sender's account not found!\n";
            return;
        }
        if(accounts.find(toAcc)==accounts.end()){
            cout<<"Receiver's account not found!\n";
            return;
        }
        if(verifyAccountPin(fromAcc) && accounts[fromAcc].withdraw(amount)){
            accounts[toAcc].deposit(amount);
            cout<<"Transfer Successful! "<<amount<<"transferred from Account "<<fromAcc<<"to Account "<<toAcc<<endl;
        }
    }

    void displayAccountDetails(const string& accNumber){
        if(accounts.find(accNumber)==accounts.end()){
            cout<<"Account not found!\n";
            return;
        }
        Account account=accounts[accNumber];
        cout<<"Account Number: "<<account.getAccountNumber()<<endl;
        cout<<"Account Holder: "<< account.getName()<<endl;
        cout<<"Balance: "<<account.getBalance()<<endl;
    }
};

int main(){
    Bank bank;
    int choice;
    string accNumber,accName,accPin,fromAcc,toAcc;
    double amount,initialDeposit;
    do{
        cout<<"\n---- Online Banking System ----\n";
        cout<<"1. Create Account\n";
        cout<<"2. Deposit\n";
        cout<<"3. Withdraw\n";
        cout<<"4. Transfer\n";
        cout<<"5. Account Details\n";
        cout<<"6. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter Account Number: ";
                cin>>accNumber;
                cout<<"Enter Account Holder's Name: ";
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                getline(cin, accName);
                cout<<"Set a 4-digit PIN: ";
                cin>>accPin;
                cout<<"Enter Initial Deposit: ";
                cin>>initialDeposit;
                bank.createAccount(accNumber,accName,accPin,initialDeposit);
                break;

            case 2:
                cout<<"Enter Account Number: ";
                cin>>accNumber;
                cout<<"Enter Deposit Amount: ";
                cin>>amount;
                bank.deposit(accNumber,amount);
                break;

            case 3:
                cout<<"Enter Account Number: ";
                cin>>accNumber;
                cout<<"Enter Withdrawal Amount: ";
                cin>>amount;
                bank.withdraw(accNumber,amount);
                break;

            case 4:
                cout<<"Enter Sender's Account Number: ";
                cin>>fromAcc;
                cout<<"Enter Receiver's Account Number: ";
                cin>>toAcc;
                cout<<"Enter Transfer Amount: ";
                cin>>amount;
                bank.transfer(fromAcc,toAcc,amount);
                break;

            case 5:
                cout<<"Enter Account Number: ";
                cin>>accNumber;
                bank.displayAccountDetails(accNumber);
                break;

            case 6:
                cout<<"Exiting the program.Thank you for using Online Banking System!\n";
                break;

            default:
                cout<<"Invalid choice!Please try again.\n";
        }
    } while(choice!=6);
}
