// objects created based on some condition
#include<bits/stdc++.h>
using namespace std;

class Car{
  public:
    virtual void drive() const = 0;
    virtual ~Car() {}
};

class SUV: public Car{
  public:
    void drive() const override{
      cout<<"Driving a SUV!";
    }
};

class Sedan: public Car{
  public:
    void drive() const override{
      cout<<"Driving a Sedan!";
    }
};

class CarFactory{
  public:
    virtual Car* create() const = 0;
    virtual ~CarFactory() {}
};

class SUVFactory: public CarFactory{
  public:
    Car* create() const override{
      return new SUV();
    }
};

class SedanFactory: public CarFactory{
  public:
    Car* create() const override{
      return new Sedan();
    }
};

int main(){
  CarFactory* factory = nullptr;
  string choice;
  cout<<"Enter car type (Sedan/SUV): ";
  cin>>choice;
  if(choice=="SUV"){
    factory = new SUVFactory();
  }else{
    factory = new SedanFactory();
  }
  if(factory!=nullptr){
    Car* mycar = factory->create();
    mycar->drive();
    delete mycar;
  }else{
    cout<<"invalid car type";
  }
  delete factory;
  return 0;
}