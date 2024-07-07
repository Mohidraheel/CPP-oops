#include<iostream>
using namespace std;

class medicine
{
    protected:
    string name;
    string formula;
    double retail_price;
    string manufacture_date;
    string expiration_date;
    public:
    medicine()
    {
        name="";
        formula="";
        retail_price=0;
        manufacture_date="";
        expiration_date="";
    }
    medicine(string name, string formula,double retail_price,string manufacture_date,string expiration_date)
    {
        this->name=name;
        this->formula=formula;
        this->retail_price=retail_price;
        this->manufacture_date=manufacture_date;
        this->expiration_date=expiration_date;
    }
    string get_name()
    {
        return name;
    }
    string get_formula()
    {
        return formula;
    }
    double get_retail_price()
    {
        return retail_price;
    }
    string get_manufacture_date()
    {
        return manufacture_date;
    }
    string get_expiration_date()
    {
        return expiration_date;
    }
    virtual void print()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Formula: "<<formula<<endl;
        cout<<"Retail Price: "<<retail_price<<endl;
        cout<<"Manufacture Date: "<<manufacture_date<<endl;
        cout<<"Expiration Date: "<<expiration_date<<endl;
    }
    bool operator==(medicine m)
    {
        return (m.expiration_date==expiration_date);
    }

};

class tablet:public medicine
{
    protected:
    double sucrose_level;
    public:
    tablet(string name,string formula,double retail_price,string manufacture_date,string expiration_date):medicine(name, formula, retail_price, manufacture_date,expiration_date)
    {
        sucrose_level=0;
    }
    void set_sucrose_level(double level)
    {
        if(level>1 || level<0)
        {
            cout<<"Invalid Sucrose Level"<<endl;
            return;
        }
        else
        {
            sucrose_level=level;
        }
      
    }
    void print()override
    {
        cout<<"Name:"<<get_name()<<endl;
        cout<<"Formula:"<<get_formula()<<endl;
        cout<<"Retail Price:"<<get_retail_price()<<endl;
        cout<<"Manufacture Date:"<<get_manufacture_date()<<endl;
        cout<<"Expiration Date:"<<get_expiration_date()<<endl;
        cout<<"Sucrose Level:"<<sucrose_level<<endl;
    }

};

class capsule:public medicine
{
    double absorption;
    public:
    capsule(string name,string formula,double retail_price,string manufacture_date,string expiration_date):medicine(name, formula, retail_price, manufacture_date,expiration_date)
    {
        absorption=0;
    }
    void set_absorption(double a)
    {
        if(a>100.0 || a<0.0)
        {
            cout<<"Invalid Absorption"<<endl;
            return;
        }
        else
        {
            absorption=a;
        }
        
    }
    void print()override
    {
        cout<<"Name:"<<get_name()<<endl;
        cout<<"Formula:"<<get_formula()<<endl;
        cout<<"Retail Price:"<<get_retail_price()<<endl;
        cout<<"Manufacture Date:"<<get_manufacture_date()<<endl;
        cout<<"Expiration Date:"<<get_expiration_date()<<endl;
        cout<<"Absorption:"<<absorption<<endl;
    }
};

class syrup:public medicine
{
    public:
    syrup(string name,string formula,double retail_price,string manufacture_date,string expiration_date):medicine(name, formula, retail_price, manufacture_date,expiration_date)
    {

    }
    void print()override
    {
        cout<<"Name:"<<get_name()<<endl;
        cout<<"Formula:"<<get_formula()<<endl;
        cout<<"Retail Price:"<<get_retail_price()<<endl;
        cout<<"Manufacture Date:"<<get_manufacture_date()<<endl;
        cout<<"Expiration Date:"<<get_expiration_date()<<endl;
    }
};

class pharmacist
{
    public:
    // only structure as per scenario
    void search_medicine(string f)
    {
        cout<<"Searching"<<endl;
    }
};

class counter
{
    int revenue;

   
    public:
    counter(int r)
    {
        revenue=r;
    }
    void search_medicine(string n)
    {
        cout<<"searching"<<endl;
    }
    void update_revenue(double r)
    {
        cout<<"updating revenue"<<endl;
        revenue+=r;
    }

};
int main()
{

    tablet tablet1("Panadol", "CH3CHOO", 150.0, "2022-02-01", "2024-12-31");
    capsule capsule1("Moxihil", "D20", 200.0, "2022-03-01", "2025-12-31");
    syrup syrup1("Brufen", "CH4", 250.0, "2022-04-01", "2026-12-31");
    tablet1.set_sucrose_level(0.5);
    capsule1.set_absorption(50.0);
    

    tablet1.print();
    cout<<endl;
    capsule1.print();
    cout<<endl;
    syrup1.print();
    cout<<endl;

    if(tablet1==capsule1)
    {
        cout<<"both will expire at same date"<<endl;
    }
    else
    {
        cout<<"both will not expire at same date"<<endl;
    }

    
    pharmacist pharmacist;
    counter counter(100);

   
    pharmacist.search_medicine("CH4O2");
    cout<<endl;
    counter.search_medicine("Medicine 1");

    counter.update_revenue(100.0);

return 0;
}
