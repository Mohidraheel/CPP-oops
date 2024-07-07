#include<iostream>
using namespace std;
template<class t,class y>

class pet
{
    protected:
    t name;
    y age;
    public:
    pet(t name,y age)
    {
        this->name=name;
        this->age=age;
    }
    virtual void makeSound()=0;
    virtual void display()=0;
};
template<class t,class y>
class cat:public pet<t,y>
{
    public:
    cat(t name,y age):pet<t,y>(name,age)
    {}
    void makeSound()
    {
        cout<<"Meow"<<endl;
    }
    void display()
    {
        cout<<"name:"<<this->name<<" "<<"age:"<<this->age<<endl;
    
    }



};
template<class t,class y>
class dog:public pet<t,y>
{
    public:
    dog(t name,y age):pet<t,y>(name,age)
    {}
    void makeSound()
    {
        cout<<"Woof"<<endl;
    }
    void display()
    {
        cout<<"name:"<<this->name<<" "<<"age:"<<this->age<<endl;
    }
    
};
template<class t,class y>
class bird:public pet<t,y>
{
    public:
    bird(t name,y age):pet<t,y>(name,age)
    {}
    void makeSound()
    {
        cout<<"Chirp"<<endl;
    }
    void display()
    {
        cout<<"name:"<<this->name<<" "<<"age:"<<this->age<<endl;
    }
};
int main()
{
    cat<string,int> c1("cat1",4);
    c1.display();
    c1.makeSound();
    
    cout<<endl;
    dog<string,int> d1("dog1",5);
    d1.display();
    d1.makeSound();

    cout<<endl;
    bird<string,int> b1("bird1",6);
    b1.display();
    b1.makeSound();

    
return 0;
}
