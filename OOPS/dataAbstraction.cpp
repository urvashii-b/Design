// exposing only essential details to the outside world while hiding internal implementation details.
#include<bits/stdc++.h>
using namespace std;

class BankAccInterface{
  public:
    virtual void deposit(double amt) = 0;
    virtual void withdraw(double amount) = 0;
    virtual double getBalance() = 0;
};

class Bank: public BankAccInterface{
  private:
    string accountHolder;
    double balance;

    bool canWithdraw(double amt){
      if(balance>=amt){
        return true;
      }
      return false;
    }
  public:
  // constructor
    Bank(string name, double initialAmt){
      accountHolder = name;
      balance = initialAmt;
    }

    void deposit(double amt) override{
      if(amt>0){
        balance+=amt;
        cout<<"deposit successful!!"<<endl;
      }else{
        cout<<"invalid deposit amount.."<<endl;
      }
    }

    void withdraw(double amt) override{
      if(canWithdraw(amt) && amt>0){
        balance-=amt;
        cout<<"Withdraw successful!!"<<endl;
      }else{
        cout<<"Insufficient funds."<<endl;
      }
    }

    double getBalance() override{
      return balance;
    }
};

int main(){
  BankAccInterface* myAcc = new Bank("Urvashi", 10000.00);
  cout<<"Initial balance: "<<myAcc->getBalance()<<endl;
  myAcc->deposit(200);
  myAcc->withdraw(1000);
  cout<<"Final balance: "<<myAcc->getBalance()<<endl;
  delete myAcc;
  return 0;
}