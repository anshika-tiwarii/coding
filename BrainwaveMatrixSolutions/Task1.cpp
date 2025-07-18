#include<bits/stdc++.h>
using namespace std;
class ATM{
private:
    int pin;
    double balance;
    vector <string> transaction_history;

public:
    ATM(int userPin,double initialBalance):pin(userPin),balance(initialBalance){
        transaction_history.push_back("Initial Balance: Rs. " + to_string(initialBalance));
    }

    bool authenticate(int enteredPin){
        return(enteredPin==pin);
    }

    void displayBalance()const{
        cout<<"Your current balance is: Rs. "<<balance<<endl;
    }

    void deposit(double amount){
        if(amount>0){
            balance+=amount;
            cout<<"Rs."<<amount<<"Deposited Successfully"<<endl;
            transaction_history.push_back("Deposited Rs. " + to_string(amount));
            displayBalance();
        }
        else{
            cout<<"Invalid Deposit Amount"<<endl;
        }
    }

    void withdraw(double amount){
        if(amount>0 && amount<=balance){
            balance-=amount;
            cout<<"Rs. "<<amount<<"Withdrawn Successfully"<<endl;
            transaction_history.push_back("Withdrawn Rs. " +to_string(amount));
            displayBalance();
        }
        else{
            cout<<"Insufficient Balance In Your Account or Invalid Amount!!"<<endl;

        }
    }

    void changePin(){
        int currentPin;
        cout<<"Please enter your current PIN: ";
        cin>>currentPin;
        if(authenticate(currentPin)){
            int newPin, confirmPin;
            cout<<"Please enter new PIN: ";
            cin>>newPin;
            cout<<"Please confirm PIN: ";
            cin>>confirmPin;
            if(newPin==confirmPin){
                pin=newPin;
                cout<<"PIN updated successfully!!"<<endl;
            }
            else{
                cout<<"PINs do not match,updation failed!!"<<endl;
            }
        }
        else{
            cout<<"Invalid current PIN!!"<<endl;
        }
    }

    void viewTransactionHistory() const{
        cout<<"\n----Transaction History----"<<endl;
        for(const string transaction: transaction_history){
            cout<<transaction<<endl;
        }
    }
};

int main(){
    int userPin=5678;
    int initialBalance=50000;
    ATM atm(userPin,initialBalance);
    cout<<"WELCOME TO THE ATM!!"<<endl;
    int enteredPin;
    cout<<"Please Enter Your PIN: ";
    cin>>enteredPin;
    if(!atm.authenticate(enteredPin)){
        cout<<"Incorrect PIN";
    }
    int choice;
    do{
        cout<<"\n----ATM MENU----"<<endl;
        cout<<"Please select from the following options!"<<endl;
        cout<<"1.Check Balance"<<endl;
        cout<<"2.Deposit Money"<<endl;;
        cout<<"3.Withdraw Money"<<endl;
        cout<<"4.Change PIN"<<endl;
        cout<<"5.View Transaction History"<<endl;
        cout<<"6.EXIT"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                atm.displayBalance();
                break;
            case 2:
            {
                double depositAmount;
                cout<<"Enter amount to deposit!"<<endl;
                cin>>depositAmount;
                atm.deposit(depositAmount);
                break;
            }
            case 3:
            {
                double withdrawAmount;
                cout<<"Enter amount to withdraw"<<endl;
                cin>>withdrawAmount;
                atm.withdraw(withdrawAmount);
                break;
            } 
            case 4:
            {
                atm.changePin();
                break;
            } 
            case 5:
            {
                atm.viewTransactionHistory();
                break;
            }
            case 6:
            {
                cout<<"Thank you for using the ATM"<<endl;
                break;
            }
            default:
                cout<<"Invalid Option,Please Try Again"<<endl;
        }
    }while(choice!=6);
}