// to prevent class explosion - addditional features keep on getting added to the base class
#include<bits/stdc++.h>
using namespace std;

class Pizza{
  public:
    virtual string getDesc() const = 0;
    virtual double getCost() const = 0;
    virtual ~Pizza() {}
};

class BasePizza : public Pizza{
  public:
    string getDesc() const override{
      return "Plain Pizza";
    }
    double getCost() const override{
      return 250.00;
    }
};

class ToppingDecorator: public Pizza{
  protected:
    Pizza* pizza;
  public:
    ToppingDecorator(Pizza* p): pizza(p) {}
    virtual ~ToppingDecorator() {}
};

class Cheese: ToppingDecorator{
  public:
  Cheese(Pizza* p): ToppingDecorator(p){}
  string getDesc() const override{
      return pizza->getDesc+ ", Cheese";
    }
    double getCost() const override{
      return pizza->getCost+15.00;
    }
};
class Pepperoni: ToppingDecorator{
  public:
  Pepperoni(Pizza* p): ToppingDecorator(p){}
  string getDesc() const override{
      return pizza->getDesc+ ", Pepperoni";
    }
    double getCost() const override{
      return pizza->getCost+30.00;
    }
};