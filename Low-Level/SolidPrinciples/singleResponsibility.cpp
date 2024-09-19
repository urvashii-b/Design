// S - Single responsibility principle: a class should have only one reason to change.

#include<bits/stdc++.h>
using namespace std;

class Employee{
  private:
    string name;
    double salary;

  public:
    Employee(string empName, double empSalary){
      name = empName;
      salary = empSalary;
    }

    void displayDetails() const{
      cout<<"Employee name: "<<name<<endl;
      cout<<"Employee salary: "<<salary<<endl;
    }

    string getName() const{
      return name;
    }

    double getSalary() const{
      return salary;
    }
};

class ReportGenerator{
  public:
  
    void generateReport(const Employee& employee) const{
      cout<<"The employee, "<<employee.getName()<<" has a salary of"<<employee.getSalary()<<endl;
    }
};

int main(){

  Employee emp("Urvashi", 100.0);
  emp.displayDetails();

  ReportGenerator rep;
  rep.generateReport(emp);

  return 0;
}