
#include <iostream>
#include <list>
// #include <string.h>
// #include <cstring>

using namespace std;

// Employee coming in and going
// DEpartment -> Employee
// User -> HR Team ,
// That user add employee in one of the dpt

class Employee
{
private:
    string name;
    int emp_id;
    double salary;

public:
    Employee(string a, int e, double d)
    {
        this->name = a;
        this->emp_id = e;
        this->salary = d;
    }

    void Print()
    {
        cout << this->name << " " << this->emp_id << " " << this->salary << endl;
    }

    ~Employee(){
        cout << "Dest. called for " << this->emp_id << endl;
    }
};

class Department
{
private:
    // Employee* emp;
    list<Employee *> emplist;

public:
    void addEmp(Employee *e)
    {
        emplist.push_back(e);
    }

    void remEmp(Employee *e)
    {
        emplist.remove(e);
    }

    void printEmp()
    {
        for (auto i : emplist)
        {
            i->Print();
        }
    }

    ~Department(){
        cout << "Dpt. deleted" << endl;
    }
};

int main()
{

    Department *HR = new Department();

    Employee *e1 = new Employee("Pratik", 1, 100000);
    Employee *e2 = new Employee("Ritik", 2, 100000);

    HR->addEmp(e1);
    HR->addEmp(e2);

    HR->printEmp(); //

    cout << "---------------" << endl;
    HR->remEmp(e2);
    HR->printEmp();

    delete e1;
    delete e2;
    delete HR;

    return 0;
}
