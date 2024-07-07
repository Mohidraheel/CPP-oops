#include <iostream>
using namespace std;

class Employee
{
protected:
    const int employeeNumber;
    string employeeName;
    string phoneNumber;

public:
    Employee(int num, string name, string phoneNo) : employeeName(name), employeeNumber(num), phoneNumber(phoneNo) {}
};

class Manager : public Employee
{
    string departmentName;
    double salary;

public:
    Manager(int num, string name, string phoneNo, string dep, double salary) : Employee(num, name, phoneNo), departmentName(dep), salary(salary) {}

    void display()
    {
        cout << "Employee Number: " << employeeNumber << endl;
        cout << "Employee Name: " << employeeName << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Department Name: " << departmentName << endl;
        cout << "Salary: " << salary << endl;
    }
    double getsalary()
    {
        return salary;
    }
};

class organizations
{
    Manager *m[10];
    int count;

public:
    organizations()
    {
        count = 0;
    }
    void add_manager(Manager *mm)
    {
        if (count < 10)
        {
            m[count] = mm;
            count++;
        }
    }
    void check()
    {
        int max1 = 0;
        int max2 = 0;
        for (int i = 0; i < count; i++)
        {

            if (m[i]->getsalary() > max1)
            {
                max1 = m[i]->getsalary();
                max2=i;
            }
        }
        for (int i = 0; i < count; i++)
        {
            if (max2 == i)
            {
                cout << "This employee has a highest salary" << endl;
                m[i]->display();
            }
        }
    }
    void display()
    {
        for (int i = 0; i < count; i++)
        {
            m[i]->display();
        }
    }
};

int main()
{

    Manager manager1(1, "John Doe", "1234567890", "Marketing", 50000.0);
    Manager manager2(2, "Jane Smith", "9876543210", "HR", 80000.0);
    Manager manager3(3, "Peter Smith", "1234567890", "idk", 70000.0);
    organizations o;
    o.add_manager(&manager1);
    o.add_manager(&manager2);
    o.add_manager(&manager3);
    o.display();
    cout << endl;
    o.check();

    return 0;
}