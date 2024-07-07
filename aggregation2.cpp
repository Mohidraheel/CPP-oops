#include <iostream>
using namespace std;
class employee
{
    string name;
    string id;
    int salary;

public:
    employee(string name, string id, int salary)
    {
        this->name = name;
        this->id = id;
        this->salary = salary;
    }
    int get_salary()
    {
        return salary;
    }
    string get_name()
    {
        return name;
    }

    string get_id()
    {
        return id;
    }

    void display()
    {
        cout<<"name:" << name << endl;
        cout<<"id:" << id << endl;
        cout<<"salary:" << salary << endl;
        cout<<endl;
    }
};
class company
{
    string name;
    string location;
    int sum1 = 0;
    int max1 = 0;
    int min1 = 0;
    int mx = 0;
    int mn = 0;

public:
    employee *e[4];
    company(string name, string location)
    {
        this->name = name;
        this->location=location;        
    }

    int salary()
    {
        double sum = 0;
        for (int i = 0; i < 4; i++)
        {
            sum = sum + e[i]->get_salary();
        }
        sum1=sum;
        return sum1;
    }
    
    void check()
    {
        int max = 0;
        int j = 0;
        for (int i = 0; i < 4; i++)
        {
            if (e[i]->get_salary() > max)
            {
                max = e[i]->get_salary();
                j = i;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            if (i == j)
            {
                cout << "highest salary is " << endl;
                cout << e[i]->get_name() << endl;
                cout << e[i]->get_id() << endl;
                cout << e[i]->get_salary() << endl;
                break;
            }
        }
    }
    void check2()
    {
        int min = e[0]->get_salary();
        int k = 0;
        for (int i = 0; i < 4; i++)
        {
            if (min > e[i]->get_salary())
            {
                min = e[i]->get_salary();
                k = i;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (i == k)
            {
                cout << "lowest salary is " << endl;
                cout << e[i]->get_name() << endl;
                cout << e[i]->get_id() << endl;
                cout << e[i]->get_salary() << endl;
                break;
            }
        }
    }

    void display()
    {
        cout<<"company name:" << name << endl;
        cout<<"location:" << location << endl;
        cout<<"total salary:" << salary() << endl;
        check2();
        check();
    }
};
int main()
{
    employee *e=new employee[4]{

    employee("mohid", "23k-3000", 50),
    employee("hassan", "23k-0625", 40),
    employee("hani", "23k-7000", 30),
    employee("basit", "23k-9400", 46),
    
    };
    company c("british council","karaaz");
    for(int i=0;i<4;i++)
    {
        c.e[i]=&e[i];
    }
    for(int i=0;i<4;i++)
    {
        c.e[i]->display();
    }

    c.display();
    return 0;
}
