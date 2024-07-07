#include <iostream>
#include<string.h>
using namespace std;
class darazperson_data
{
protected:
    string firstname;
    string lastname;
    string address;
    string city;
    string state;
    string zip;
    string phone;

public:
    string getLastName() const
    {
        return lastname;
    }
    string getFirstName() const
    {
        return firstname;
    }
    string getAddress() const
    {
        return address;
    }
    string getCity() const
    {
        return city;
    }
    string getState() const
    {
        return state;
    }
    string getZip() const
    {
        return zip;
    }
    string getPhone() const
    {
        return phone;
    }

    void setLastName(string lname)
    {
        lastname = lname;
    }
    void setFirstName(string fname)
    {
        firstname = fname;
    }
    void setAddress(string addr)
    {
        address = addr;
    }
    void setCity(string cty)
    {
        city = cty;
    }
    void setState(string st)
    {
        state = st;
    }
    void setZip(string zp)
    {
        zip = zp;
    }
    void setPhone(string ph)
    {
        phone = ph;
    }
};
class customer_data : public darazperson_data
{
    int customerNumber;
    int loyaltyPoints;

public:
    customer_data()
    {
    }

    int getCustomerNumber() const
    {
        return customerNumber;
    }
    int getLoyaltyPoints() const
    {
        return loyaltyPoints;
    }

    void setCustomerNumber(int phonenum)
    {
        customerNumber = phonenum;
    }
    void setLoyaltyPoints(int points)
    {
        loyaltyPoints = points;
    }
    void display()
    {
        cout << "First Name: " << getFirstName() << endl;
        cout << "Last Name: " << getLastName() << endl;
        cout << "Address: " << getAddress() << endl;
        cout << "City: " << getCity() << endl;
        cout << "State: " << getState() << endl;
        cout << "Customer Number: " << customerNumber << endl;
        cout << "Loyalty Points: " << loyaltyPoints << endl;
    }
};
class daraz_loyality
{
    public:
    void addloyalitypoint(int point,customer_data &c)
    {
        if(point>0)
        {
            int currentpoint=c.getLoyaltyPoints();
            c.setLoyaltyPoints(currentpoint+point);
            cout<<"loyalty point: "<< point <<" added to customer number "<<c.getCustomerNumber()<<endl;
            cout<<"Total points now : "<<c.getLoyaltyPoints()<<endl;
        }
        else
        {
            cout<<"loyalty point cannot be negative"<<endl;
        }
    }

    void redeemedloyalitypoint(int point,customer_data &c)
    {
        int currentpoint=c.getLoyaltyPoints();
        if(point>0&& currentpoint>=point)
        {
            c.setLoyaltyPoints(currentpoint-point);
            cout<<"loyalty point: "<< point <<" redeemed from customer number "<<c.getCustomerNumber()<<endl;
            cout<<"Total points now : "<<c.getLoyaltyPoints()<<endl;
        }
        else
        {
            cout<<"loyalty point cannot be negative"<<endl;
        }

    }
    void display1(customer_data& c)
    {
        c.display();
    }

};
int main()
{
    cout<<"mohid raheel khan 23k-3000"<<endl;
    customer_data c;
    c.setFirstName("Abdul");
    c.setLastName("hani");
    c.setAddress("123 Main St");
    c.setCity("New York");
    c.setState("NY");
    c.setZip("10001");
    c.setPhone("03055047651");
    c.setCustomerNumber(1234);
    c.setLoyaltyPoints(100);
    daraz_loyality d;
    d.addloyalitypoint(10,c);
    d.redeemedloyalitypoint(50,c);
    d.display1(c);

    return 0;
}
