#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
    string gender;
public:
    Person(string n, int a, string g) : name(n), age(a), gender(g) {}

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }
};

class Employee : public Person {
private:
    int empid;
    double salary;
public:
    Employee(string n, int a, string g, int id, double sal) : Person(n, a, g), empid(id), salary(sal) {}

    void display() {
        Person::display();
        cout << "Employee ID: " << empid << endl;
        cout << "Salary: $" << salary << endl;
    }
};

class Manager : public Employee {
private:
    string department;
public:
    Manager(string n, int a, string g, int id, double sal, string dept) : Employee(n, a, g, id, sal), department(dept) {}

    void display() {
        Employee::display();
        cout << "Department: " << department << endl;
    }
};

int main() {
    // Person p("Alice", 30, "Female");
    // cout << "Person Details:" << endl;
    // p.display();
    // cout << endl;

    // Employee e("Bob", 35, "Male", 1001, 50000.0);
    // cout << "Employee Details:" << endl;
    // e.display();
    // cout << endl;

    Manager m("Charlie", 40, "Male", 2001, 70000.0, "Engineering");
    cout << "Manager Details:" << endl;
    m.display();
    cout << endl;

    return 0;
}
