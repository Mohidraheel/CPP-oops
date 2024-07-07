#include <iostream>
using namespace std;
class movie
{
public:
    string name;
    int price;
    int availability = 1;
    string year;

    movie(string name, int price, int availability, int year)
    {
        this->name = name;
        this->price = price;
        this->availability = availability;
        this->year = year;
    }
    void display()
    {

        cout << "movie:" << endl;
        cout << "price:" << price << endl;
        cout << "year:" << year << endl;
        if (availability == 1)
        {
            cout << "available" << endl;
        }
        else
        {
            cout << "not available" << endl;
        }
    }
};
class person
{
    int totalbill;
    string name;
    int age;
    int bill;
    int count = 0;
    string n;
    int a;
    int j;
    string membership;

public:
    person(string name, int age,string membership)
    {
        this->membership = membership;
        this->name = name;
        this->age = age;
        bill = 0;
        j=0;
        
    }
    void purchase(movie m[])
    {
        cout << "enter number of movies you want to purchase" << endl;
        cin >> a;
        while (j < a)
        {
            cout << "enter name of movie" << endl;
            cin >> n;
            if (count < 5)
            {

                for (int i = 0; i < 5; i++)
                {
                    if (m[i].name == n)
                    {
                        if (m[i].availability == 1)
                        {
                            m[i].availability = 0;
                            bill += m[i].price;
                            cout << m[i].name << " has been purchased" << endl;
                            count++;
                            j++;
                        }
                        else
                        {
                            j++;
                            cout << m[i].name << " is not available" << endl;
                        }
                    }
                }
            }
            n = " ";
        }
    }
    void bill2()
    {
        if(membership==" ")
        {
            cout << "total bill:" << bill << endl;

        }
        else
        {
            if(membership=="gold")
            {
                totalbill = bill;
                bill=bill*0.1;
                totalbill=totalbill+bill;
                
                cout << "total bill:" << totalbill << endl;
            }
            else
            {
                if(membership=="silver")
                {
                    totalbill = bill;
                    bill=bill*0.15;
                    totalbill=totalbill+bill;
                    
                    cout << "total bill:" << totalbill << endl;
                }
                else
                {
                    if(membership=="premium")
                    {
                        totalbill = bill;
                        bill=bill*0.2;
                        totalbill=totalbill+bill;
                        
                        cout << "total bill:" << totalbill << endl;
                    }
                   
                }
            }
        }
        
    }
};
int main()
{
    movie m[5] =
        {
            {"hello1", 1000, 1, 2019},
            {"hell2", 2000, 0, 2022},
            {"hell3", 4000, 1, 2023},
            {"hell4", 1500, 0, 2012},
            {"hell5", 500, 1, 2015}

        };
    person p1("mohid", 18,"gold");
    p1.purchase(m);
    p1.bill2();

    return 0;
}
