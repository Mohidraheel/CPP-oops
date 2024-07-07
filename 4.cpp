#include <iostream>
#include <cmath>
using namespace std;
class rollercoaster
{
    string name;
    double height;
    double length;
    double speed;
    int capacity;
    double current_passenger;
    bool currently_inprogress;

public:
    rollercoaster() : name("rollercoaster"), height(500), length(2000), capacity(20), currently_inprogress(false), speed(0), current_passenger(0) {}

    rollercoaster(string n, double h, double l, int c, double sp ) : name(n), height(h), length(l), speed(sp), currently_inprogress(false)
    {

        if (c % 2 != 0 && c % 3 != 0)
        {
            round(c / 2);
        }

        if (c < 3)
        {
            c = 3;
        }
    }

    void set_name(string n)
    {
        name = n;
    }

    string get_name()
    {
        return name;
    }

    void set_height(double h)
    {
        height = h;
    }

    double get_height()
    {
        return height;
    }

    void set_length(double l)
    {
        length = l;
    }

    double get_length()
    {
        return length;
    }

    void set_capacity(int c)
    {
        if (c % 2 != 0 || c % 3 != 0)
        {
            round(c / 2);
        }

        if (c < 3)
        {
            c = 3;
        }
        capacity = c;
    }

    int get_capacity()
    {
        return capacity;
    }

    void set_speed(double sp)
    {
        speed = sp;
    }

    double get_speed()
    {
        return speed;
    }

    void set_currently_inprogress(bool i)
    {
        currently_inprogress = i;
    }

    bool get_currently_inprogress()
    {
        return currently_inprogress;
    }
   

    double get_current_passenger()
    {
        return current_passenger;
    }

    int load(int n)
    {
        int m;
        if (get_currently_inprogress() != true)
        {
            if (get_capacity() == n)
            {
                current_passenger = n;
                cout << "every one is seated successfully"<<endl;
                return 0;
            }
            else
            {
                if(get_capacity()> n)
                {
                    current_passenger = n;
                    m=get_capacity()-current_passenger;
                    cout << "few seats are empty:"<<m<<endl;
                    return 1;
                }
                else
                {
                    m=n-get_capacity();
                    current_passenger =n-m;
                    cout << "not enough seats "<<endl;
                    cout<<"these are left:"<<m<<endl;
                    return 2;
                }
            }

        }
    }

    void start(int n)
    {
        if (get_currently_inprogress() == false)
        {
            set_speed(50);
        
            load(n);
            set_currently_inprogress(true);
        }
        else
        {
            cout << "the ride is already in progress"<<endl;
        }
    }

    void stop()
    {
        if(get_currently_inprogress() ==true)
        {
            set_currently_inprogress(false);
            cout << "the ride is stopped"<<endl;
            unload();
        }
    }

    void unload()
    {
        if(get_currently_inprogress()!=true)
        {
             current_passenger=0;
             cout << "everyone is unloaded"<<endl;
        }
        else
        {
            cout << "the ride is in progress"<<endl;
        }
    }

    void accelerate()
    {
        int rollnumber=3000;
        while(rollnumber>=10)
        {
            rollnumber=rollnumber/10;
        }
        speed=speed+rollnumber;
        set_speed(speed);
        cout<<"new speed is "<<get_speed()<<endl;

    }

    void decelerate()
    {
        int rollnumber=3000;
        while(rollnumber>=10)
        {
            rollnumber=rollnumber/10;
        }
        speed=speed-rollnumber;
        set_speed(speed);
        cout<<"new speed is "<<get_speed()<<endl;
    }
}
;

int main()
{
    cout<<"mohid raheel khan 23k-3000"<<endl;
    rollercoaster r1;
    r1.start(5);
    r1.accelerate();
    r1.stop();
   
    cout<<endl;
    rollercoaster r2("ride of heaven",1000,2500,30,0);
    r2.set_capacity(30);
    r2.start(30);
    r2.accelerate();
    r2.accelerate();
    r2.decelerate();
    r2.stop();

     

    return 0;
}
