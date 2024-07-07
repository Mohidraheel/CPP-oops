#include<iostream>
using namespace std;
class engine
{
    string name;
    int model;
    bool status;

    public:
    engine(string name,int model,bool status)
    {
        this->name=name;
        this->model=model;
        this->status=status;
    }

    string getname()
    {
        return name;
    }

    int getmodel()
    {
        return model;
    }
    bool getstatus()
    {
        return status;
    }

    ~engine()
    {

    }


};
class company
{
    string comp;
    
    public:
    company(string comp)

    {
        this->comp=comp;
    }

    string getcomp()
    {
        return comp;
    }

};

class car
{
    string numberplate;
    engine *e;
    company *c;
    public:
    car(string numberplate,engine *e,company *c)
    {
        this->numberplate=numberplate;
        this->e=e;
        this->c=c;
    }

    void display()
    {
        cout<<numberplate<<" "<<e->getname()<<" "<<e->getmodel()<<endl;
        cout<<c->getcomp()<<" "<<endl;
        status();
        
    }

    bool status()
    {
        if(e->getstatus()==true)
        {
            cout<<"car is on";
            return true;
        }
        else
        {
            cout<<"car is off";
            return false;
        }
    }

};

int main()
{
   engine *e=new engine("V8",2020,true);
   company *c=new company("Toyota");
   car *c1=new car("AWB-779",e,c);
   c1->display();

   delete e;
   delete c;
   delete c1;


    cout<<endl;
   engine *e1=new engine("r8",2023,false);
   company *c11=new company("Honda");
   car *c111=new car("AWB-779",e1,c11);
   c111->display();
return 0;
}
