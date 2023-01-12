#include <string>

class Employee
{
public:
    Employee(std::string name, std::string role, int salary)
        : name_(name), role_(role), salary_(salary) {}

    std::string getName() const { return name_; }
    std::string getRole() const { return role_; }
    int getSalary() const { return salary_; }

    void setName(std::string name) { name_ = name; }
    void setRole(std::string role) { role_ = role; }
    void setSalary(int salary) { salary_ = salary; }

private:
    std::string name_;
    std::string role_;
    int salary_;
};

class Department
{
public:
    Department(std::string name) : name_(name) {}

    void addEmployee(const Employee &employee) { employees_.push_back(employee); }
    std::string getName() const { return name_; }
    std::vector<Employee> getEmployees() const { return employees_; }

private:
    std::string name_;
    std::vector<Employee> employees_;
};

/**The Employee class has three private member variables: name_, role_, and salary_. It has public member functions for getting and setting these variables, as well as a constructor that allows you to set these values when you create a new Employee object.

The Department class has a private member variable name_ and a private member variable employees_, which is a vector of Employee objects. It has a public member function addEmployee that allows you to add an employee to the department, as well as public member functions for getting the department name and the list of employees in the department.*/