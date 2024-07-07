#include <iostream>
using namespace std;

class table
{
    bool clean;
    const int capacity;
    int occupied;

public:
    table() : capacity(4), clean(true), occupied(0) {}

    table(int i) : capacity(i == 8 ? 8 : 4), clean(true), occupied(0) {}

    int getcapacity() const
    {
        return capacity;
    }
    


    bool isclean() const
    {
        return clean;
    }

    void get_table(int group)
    {
            occupied=group;
            clean = false;
            cout << "table is ocuupied" << endl;
        
    }

    void lunch()
    {
        clean = false;
        cout << "having lunch" << endl;
        
    }

    void leave()
    {
        clean = true;
        occupied=0;
        cout << "table is empty now" << endl;
        cout << "table is cleaned" << endl;
    }
};

void occupy(int group, table t[])
{
    int flag = 0;
    for (int i=0; i < 5; i++)
    {
        if (t[i].getcapacity() == group && t[i].isclean() != false)
        {
            cout << "table no." << i + 1 << " has been assigned" << endl;
            cout << "capacity: " << t[i].getcapacity() << endl;
            t[i].get_table(group);
            flag = 1;
            return;
        }
    }
    if (flag == 0)
    {
        for (int i=0; i < 5; i++)
        {

            if (t[i].getcapacity() >= group && t[i].isclean() != false)
            {
                cout << "table no." << i + 1 << " has been assigned" << endl;
                cout << "capacity: " << t[i].getcapacity() << endl;
                t[i].get_table(group);
                flag = 1;
                return;
            }
        }
    }
    if(flag==0)
    {
        cout << "table is full" << endl;
    }
}

void empty(table t[], int n)
{
    t[n].leave();
}
int main()
{
    cout<<"mohid raheel khan 23k-3000"<<endl;
    table t[5] = {table(8), table(8), table(4), table(4), table(4)};
    occupy(4, t);
    t[0].lunch();
    t[0].leave();
    cout << endl;
    occupy(6, t);
    empty(t, 1);

    return 0;
}
