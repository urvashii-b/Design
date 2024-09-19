// multiple children (is-a relationship) are implementing their methods (some children might have same overridden method implementation from base class - code duplicate)
#include<bits/stdc++.h>
using namespace std;

class PaymentStrategy{
public:
  virtual void pay(double amt) const = 0;
  virtual ~PaymentStrategy() {}
};

class CreditCardPayment: public PaymentStrategy{
  private:
    string name;
    string number;
  public:
    CreditCardPayment(const string& cardNumber, const string& cardName) : number(cardNumber), name(cardName) {}

    void pay(double amt) const override{
      cout<<"Payment for card holder "<<name<<"with card number "<<number<<"is being done for amount "<<amt<<endl;
    }
};

class PaypalPayment: public PaymentStrategy{
  private:
    string email;
  public:
    PaypalPayment(const string& emailAddress) : email(emailAddress) {}

    void pay(double amt) const override{
      cout<<"Payment for "<<amt<<"with email id "<<email<<"is processed."<<endl;
    }
};

class BitcoinPayment: public PaymentStrategy{
  private:
    string wallet;
  public:
    BitcoinPayment(const string& walletAddress) : wallet(walletAddress) {}

    void pay(double amt) const override{
      cout<<"Payment for "<<amt<<"with wallet address "<<wallet<<"is processed."<<endl;
    }
};


class ShoppingCart{
  private:
    PaymentStrategy* paymentStrategy;

  public:
    void setPaymentStrategy(PaymentStrategy* strategy){
      paymentStrategy = strategy;
    }

    void checkout(double amt){
      if(paymentStrategy!=nullptr){
        paymentStrategy->pay(amt);
      }else{
        cout<<"No payment strategy set"<<endl;
      }
    }
};

int main(){
  ShoppingCart cart;

  PaymentStrategy* credit = new CreditCardPayment("1002781627537", "Urvashi");
  cart.setPaymentStrategy(credit);
  cart.checkout(20.0);
  PaymentStrategy* paypal = new PaypalPayment("ashi@gmail.com");
  cart.setPaymentStrategy(paypal);
  cart.checkout(250.0);
  PaymentStrategy* bitcoin = new BitcoinPayment("A562F7w8");
  cart.setPaymentStrategy(bitcoin);
  cart.checkout(120.0);

  delete bitcoin;
  delete credit;
  delete paypal;

  return 0;
}