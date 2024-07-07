#include<iostream>
using namespace std;
class student
{
     string name;

    public:
    student(string n):name(n)
    {}
    
    string getname()const
    {
        name="shayan";
        return name;
    }
    // void display()
    // {
    //     cout<<name<<endl;
    // }

};
int main()
{
    student s("mohid");
    cout<<s.getname();
return 0;
}
