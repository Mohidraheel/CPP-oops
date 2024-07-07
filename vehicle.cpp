#include<iostream>
using namespace std;

class engine
{
    string engine;
    public:
    void set_engine(string e)
    {
        engine=e;
    }
    void get_engine()
    {
        cout<<engine<<endl;
    }
};

class wheels
{
    int size;
    public:
    wheels()
    {
        
    }
    void set_size(int s)
    {
        size=s;
    }
    void get_size()
    {
        cout<<size<<endl;
    }

};

class car
{
    engine e;
    wheels w[4];
    public:
    car(string m,int s)
    {
        e.set_engine(m);
        for(int i=0;i<4;i++)
        {
            w[i].set_size(s);
        }
    }
    void display()
    {
        e.get_engine();
        for(int i=0;i<4;i++)
        {
            w[i].get_size();
        }

    }
};
int main()
{
    car c1("V8",6);
    c1.display();
return 0;
}
