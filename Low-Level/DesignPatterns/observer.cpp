// whenever observable's state changes, it updates all the observers's point of views

/*
Observer Design Pattern is used to create a one-to-many relationship between objects, where one object (the "observable" or "subject") maintains a list of dependents (the "observers") and notifies them of any state changes.
*/

#include<bits/stdc++.h>
using namespace std;

class IObserver{
  public:
    virtual void update(const string& product, bool inStock) = 0;
    virtual ~IObserver() {}
};

class IObservable{
  public:
    virtual void add(IObserver* observer) = 0;
    virtual void remove(IObserver* observer) = 0;
    virtual void notify() = 0;
    virtual void setAvailability(bool available) = 0;
    virtual ~IObservable() {}
};

class User: public IObserver{
  private:
    string userName;
  public:
    User(const string& name): userName(name) {}
    void update(const string& product, bool inStock) override{
      if(inStock){
        cout<<"Notification for user "<<userName<<": "<<product<<" is back in stock!"<<endl;
      }else{
        cout<<"Notification for user "<<userName<<": "<<product<<" is out of stock!!"<<endl;
      }
    }
};

class Product: public IObservable{
  private:
    string productName;
    vector<IObserver*> observers;
    bool inStock;
  public:
    Product(const string& name): productName(name), inStock(false) {}
    void add(IObserver* obs) override{
      observers.push_back(obs);
    }
    void remove(IObserver* obs) override{
      observers.erase(remove(observers.begin(), observers.end(), obs), observers.end());
    }
    void notify() override{
      for(IObserver* obs: observers){
        obs->update(productName,inStock);
      }
    }
    void setAvailability(bool available) override{
      inStock = available;
      notify();
    }
};

int main(){
  Product prod("Amazon Echo");

  User u1("Urvashi");
  User u2("Teresha");
  User u3("John");

  prod.add(&u1);
  prod.add(&u2);
  prod.add(&u3);

  prod.setAvailability(true);
  prod.remove(&u1);
  prod.setAvailability(false);
  return 0;
}