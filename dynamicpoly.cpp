#include <iostream>
using namespace std;
class base
{
protected:
    int a;

public:
    base()
    {
        cout << "base constructor" << endl;
    }
    virtual void display(int a)
    {
        cout << "base class :" << a << endl;
    }
    virtual ~base()=0;
    
};
base::~base()
{
    cout << "base destructor" << endl;
}
class d1 : public base
{
public:
    d1()
    {
        cout << "d1 constructor" << endl;
    }
    void display(int a)
    {

        cout << "d1 class :" << a << endl;
    }
    ~d1()
    {
        cout << "d1 destructor" << endl;
    }
};
class c2 : public d1
{
public:
    c2()
    {
        cout << "c2 constructor" << endl;
    }
    void display(int a)
    {
        cout << "c2 class :" << a << endl;
    }
    ~c2()
    {
        cout << "c2 destructor" << endl;
    }
};

int main()
{
    // d1 d;
    c2 *c=new c2;
    base *b1;
    b1 = c;
    b1->display(50);
    delete b1;

    return 0;
}