#include <iostream>
using namespace std;

class A {
    protected:
    int x;
    public:

    A()
    {
        x=5;
        cout << "A()" << endl;
    }

     void display() 
    {
        cout << "A::display()" << endl;
    }

};

class B : public A {
    public:
    int y;
    B()
    {
        cout << "B()" << endl;
    }

     void display() 
    {
        cout << "B::display()" << endl;
    }
};

class C : public B {
    public:
    int z;
    C()
    {
        cout << "C()" << endl;
    }

     void display() 
    {
        cout << "C::display()" << endl;
    }
};

class D : public C {
    public:
    int w;
    D()
    {
        cout << "D()" << endl;
    }

    void display() 
    {
        cout <<  "D::display()" << endl;
    }
};



int main()
{
    C b;
    D *d = (D*)&b;
    d->display();


    return 0;
}