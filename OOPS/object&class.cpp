#include<bits/stdc++.h>
using namespace std;

class Car{
  private:
    string model;
    string make;
    int year;
    float fuelLevel;

  public:
    Car(string carModel, string carMake, int carYear){
      model = carModel;
      make = carMake;
      year = carYear;
      fuelLevel = 100.0;
    }

    void displayDetails(){
      cout << "Car Model:" << model << endl;
      cout << "Car Make:" << make << endl;
      cout << "Car Year:" << year << endl;
      cout << "Car Fuel:" << fuelLevel << "%" << endl;
    }

    void drive(float distance){
      float consumption = distance*0.1;
      if(fuelLevel>=consumption){
        fuelLevel-=consumption;
        cout<<"You drove: "<<distance<<" km. Fuel level is at: "<<fuelLevel<<"%"<<endl;
      }else{
        cout<<"Not enough to drive!!"<<endl;
      }
    }

    void refuel(float amount){
      if(amount+fuelLevel>100.0){
        fuelLevel = 100.0;
      }else{
        fuelLevel += amount;
      }
      cout<<"Fuel is at "<<fuelLevel<<"%"<<endl;
    }
};

int main(){
  Car myCar("Toyota","Corolla",2024);
  myCar.displayDetails();

  myCar.drive(50);
  myCar.refuel(1);
  myCar.drive(30);
  myCar.refuel(70);

  return 0;
}