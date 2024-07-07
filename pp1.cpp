#include <iostream>
using namespace std;
class academic
{
protected:
    int m;
    int marks;

public:
    void getid(int id)
    {
        m = id;
        cout << "calling from teacher assistant" << m << endl;
    }
};
class student : virtual public academic
{
public:
    void gpa()
    {
        cout << "calling from student" << m << endl;
    }
    void calculate_marks()
    {
        cout << "enter your marks:";
        cin >> marks;
        cout << "marks: " << marks << endl;
    }
};
class instructor : virtual public academic
{
public:
    void gpa()
    {
        cout << "calling from instructor" << m << endl;
    }
};
class teacher_assistant : public student, public instructor
{
public:
    void gpa()
    {
        cout << "calling from teacher " << m << endl;
    }
    void result()
    {
        if(marks<50)
        {
            cout << "fail" << endl;
        }
        else
        {
            cout << "pass" << endl;
        }
    }
};

int main()
{
    teacher_assistant t;
    t.getid(101);
    t.gpa();
    t.calculate_marks();
    t.result();
    return 0;
}
