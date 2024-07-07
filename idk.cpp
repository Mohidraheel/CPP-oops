#include <iostream>
using namespace std;
class vehicle
{
    protected:
    string name;
    int model;
    int year;
    int make;
    int speed;

public:
    vehicle(string name, int model, int make, int year,int speed)
    {
        cout<<"hello base"<<endl;
        this->speed = speed;
        this->name = name;
        this->model = model;
        this->make = make;
        this->year = year;
    }
     void display()
    {
        cout << name << " " << model << " " << make << " " << year <<speed<< " " <<endl;
    }
    ~vehicle()
    {
        cout<<"hello destructor"<<endl;
    }
};
class car : public vehicle
{
    public:
    car(string name, int model, int make, int year,int speed) : vehicle(name, model, make, year,speed)
    {
       cout<<"hello car"<<endl;
    }
    void display()
    {
        vehicle::display();
    }
    ~car()
    {
        cout<<"hello  car destructor"<<endl;
    }
    
};
class truck: public vehicle
{
    public:
    truck(string name, int model, int make, int year,int speed) : vehicle(name, model, make, year,speed)
    {
        cout<<"truck"<<endl;
    }
    void display()
    {
        vehicle::display();
    }

};
int main()
{
    car c1("<NAME>", 2020, 2020, 2020, 2020);
    // truck t1("<NAME>", 2020, 2020, 2020, 2020);
    c1.display();
    // t1.display();
    return 0;
}
