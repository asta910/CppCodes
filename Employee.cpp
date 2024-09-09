#include <iostream>
using namespace std;

class Employee {
protected:
    int id;
    long mbNumber;
    int salary;

public:
    Employee(int id, long number, int sal) {
        this->id = id;
        this->mbNumber = number;
        this->salary = sal;
       // cout<<"Constructor called for Employee " <<endl;
    }

    Employee() {}

    virtual void calculateSalary() {
        cout << "Calling from Employee class: ID is " << this->id << " & Mobile Number is: " << this->mbNumber << endl;
    }

    virtual ~Employee() {
      //  cout << "Destructor called for Employee class" << endl;
    }
};

class WageWorker : public virtual Employee {
    int extraHrs;
    int daysAbsent;

public:
    WageWorker(int id, long mb, int sal, int extra, int absent) : Employee(id, mb, sal) {
        this->extraHrs = extra;
        this->daysAbsent = absent;
      //  cout<<"Constructor called for WageWorker " <<endl;
    }

    WageWorker() {}

    void calculateSalary() {
        cout << "Salary of WageWorker with ID: " << id << " is: " << salary + (extraHrs * 100) - (daysAbsent * 800) << endl;
    }

    ~WageWorker() {
      //  cout << "Destructor called for WageWorker" << endl;
    }
};

class SalesManager : public virtual Employee {
    int sales;
    int advSpending;

public:
    SalesManager(int id, long nb, int sal, int sales, int advSpending) : Employee(id, nb, sal) {
        this->sales = sales;
        this->advSpending = advSpending;
      //  cout<<"Constructor called for SalesManager " <<endl;

    }

    void calculateSalary() {
        cout << "Salary of SalesManager with ID: " << id << " is: " << salary + (sales * 0.1) - advSpending << endl;
    }

    ~SalesManager() {
      //  cout << "Destructor called for SalesManager" << endl;
    }
};

class Joined : public WageWorker, public SalesManager {
public:
    Joined(int id, long nb, int sal, int extra, int absent, int sales, int advSpending)
        : Employee(id, nb, sal), WageWorker(id, nb, sal, extra, absent), SalesManager(id, nb, sal, sales, advSpending) {}

    void calculateSalary() {
        WageWorker::calculateSalary();
        SalesManager::calculateSalary();
    }
};

int main() {
    cout<<endl<<endl;

    Joined wageWorker1(1, 1234567890, 50000, 10, 4, 0, 0);
    wageWorker1.calculateSalary();

    cout<<endl<<endl;

    Joined salesManager1(2, 27218576999, 40000, 0, 0, 10000, 5000);
    salesManager1.calculateSalary();

    cout<<endl<<endl;
    return 0;
}
