
#include<iostream>
using namespace std;
class staff
{
    
    public:
    virtual void displayInfo()
    {}
    virtual void calculateSalary()
    {}

};

class professor:public staff
{
    string name;
    int id;
    int course_taught;
    double salary;
    public:
    professor(string name, int id, int course_taught)
    {
        this->name = name;
        this->id = id;
        this->course_taught = course_taught;
    }
    void calculateSalary()
    {
        salary = course_taught * 1500;
    }
    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Number of courses taught: " << course_taught << endl;
        cout << "Salary: " << salary << endl;
    }


};

class admin:public staff
{
    string name;
    int id;
    double salary;
    int overtime;
    public:
    admin(double salary, string name, int id)
    {
        this->name = name;
        this->id = id;
        this->salary = salary;
    }
    void calculateSalary()
    {
        cout<<"enter overtime hours:";
        cin>>overtime;
        salary = salary + (overtime * 50);

    }
    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << endl;
    }

};

class support:public staff
{
    string name;
    int id;
    double salary;
    int hours;
    public:
    support(string name, int id)
    {
        this->name = name;
        this->id = id;
    }
    void calculateSalary()
    {
        cout<<"enter hours:";
        cin>>hours;
        salary = hours * 70;
    }
    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main()
{
    staff* s;
    professor p("shafique ahmed",101,2);
    s=&p;
    s->calculateSalary();
    s->displayInfo();
    cout<<endl;

    admin a(100000,"abdul saeed",102);
    s=&a;
    s->calculateSalary();
    s->displayInfo();
    cout<<endl;

    support s1("Mohid",103);
    s=&s1;
    s->calculateSalary();
    s->displayInfo();

}