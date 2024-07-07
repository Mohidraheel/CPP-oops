#include <iostream>
#include <string.h>
using namespace std;
class restaurant
{
    string name;
    string location;
    string menu[6];
    double price[6];
    string coupan_codes[5];
    double bills;
    static int count;
    bool status[5];

public:
    restaurant(string name, string location) : name(name), location(location)
    {
    }

    void add_menu(string menu[])
    {
        for (int i = 0; i < 6; i++)
        {
            this->menu[i] = menu[i];
        }
    }

    void add_price(double price[])
    {
        for (int i = 0; i < 6; i++)
        {
            this->price[i] = price[i];
        }
    }

    void add_coupan_codes(string coupan_codes[])
    {
        for (int i = 0; i < 5; i++)
        {

            this->coupan_codes[i] = coupan_codes[i];
            status[i] = false;
        }
    }
    string *get_coupan_codes()
    {
        return coupan_codes;
    }

    bool *get_status()
    {
        return status;
    }

    string get_name()
    {
        return name;
    }

    string get_location()
    {
        return location;
    }

    void display()
    {
        cout << name << "  Mohid Raheel Khan 23k-3000" << endl;
        cout << location << endl;
        cout << "menu" << endl;

        for (int i = 0; i < 6; i++)
        {
            cout << menu[i] << "  " << price[i] << endl;
        }
    }

    static int get_coupan_count()
    {
        return count;
    }

    void generate_bill()
    {
        string n;
        int quantity;
        int c;
        double bill = 0;
        cout << "enter the items you order" << endl;
        cin >> c;
        for (int i = 0; i < c; i++)
        {
            cin.ignore();
            cout << "enter the name of the item" << endl;
            getline(cin, n);
            cout << "enter the quantity of the item" << endl;
            cin >> quantity;
            for (int j = 0; j < 6; j++)
            {
                if (menu[j] == n)
                {
                    bill += price[j] * quantity;
                }
            }
        }
        bills = bill;
    }

    void discount()
    {

        bills = bills * 0.5;
    }

    void display_bill()
    {

        generate_bill();
        discount();
        cout << "your bill with 50% discount is:" << bills << endl;
    }
};
int restaurant ::count = 0;

class bogo
{
    string coupan_code;
    string valid_from;
    string valid_until;
    restaurant *r[2];

public:
    bogo(string coupan_code, string valid_from, string valid_until) : coupan_code(coupan_code), valid_from(valid_from), valid_until(valid_until) {}

    void set(restaurant *r)
    {
        for (int i = 0; i < 2; i++)
        {
            this->r[i] = &r[i];
        }
    }

    string get_coupan_code()
    {
        return coupan_code;
    }
    bool is_valid()
    {
        string restaurant;
        string current_date = "17-02-2024";
        cout << "enter the restaurant name:" << endl;
        getline(cin, restaurant);

        for (int i = 0; i < 2; i++)
        {

            if (restaurant == r[i]->get_name())
            {
                if (current_date <= valid_until && current_date <= valid_from)
                {

                    for (int j = 0; j < 5; j++)
                    {
                        if (get_coupan_code() == r[i]->get_coupan_codes()[j])
                        {
                            r[i]->get_status()[j] = true;
                            r[i]->display_bill();
                            return true;
                        }
                    }
                }
            }
            else
            {
                return false;
            }
        }
    }
};
// maximum bogo coupan at a time is 5
class user
{
    string name;
    int age;
    string mobile_num;
    string coupan_codes[5];
    int coupan_count = 0;
    bogo *b1;

public:
    user(string name, int age, string mobile_num, int n) : name(name), age(age), mobile_num(mobile_num), coupan_count(n) {}

    string get_name()
    {
        return name;
    }

    int get_age()
    {
        return age;
    }

    string get_mobile_num()
    {
        return mobile_num;
    }

    int get_coupan_count()
    {
        return coupan_count;
    }

    void setbogo(bogo b)
    {
        b1 = &b;
    }

    void accumalate(string coupan)
    {
        if (coupan_count < 5)
        {
            coupan_codes[coupan_count++] = coupan;

            cout << "coupan code accumalated successfully" << endl;
        }
        else
        {
            cout << "maximum coupan code is 5" << endl;
        }
    }

    void valid(string restaurant)
    {
        for (int i = 0; i < coupan_count; i++)
        {

            if (coupan_codes[i] != "")
            {
                cout << "coupan is unused" << endl;
            }
        }
    }

    bool redeemed(string restaurant, string coupan)
    {
        for (int i = 0; i < 5; i++)
        {
            if (coupan.substr(0, 2) == "FH" || coupan.substr(0, 2) == "PB")
            {
                if (coupan_codes[i] == coupan)
                {
                    valid(restaurant);
                    coupan_codes[i] = "";

                    cout << "coupan redeemed successfully for restaurant:" << restaurant << endl;
                    b1->is_valid();
                    return true;
                }
            }
            else
            {
                cout << "coupan already used" << endl;
                return false;
            }
        }
    }
};
int main()
{
    restaurant r[2] = {
        restaurant("foodhaven", "karachi"),
        restaurant("pixelbites", "lahore")};

    string foodHavenMenu[6] = {
        "sushi",
        "pad Thai",
        "mango Tango",
        "california Roll",
        "green Curry",
        "tempura"};

    double foodHavenPrice[] = {
        10.99, 8.99, 5.99, 9.99, 11.99, 7.99

    };
    string foodHavencoupan[5] = {
        "FH-BOGO-12345", "FH-BOGO-12355", "FH-BOGO-12555", "FH-BOGO-15555", "FH-BOGO-55555"};
    r[0].add_menu(foodHavenMenu);
    r[0].add_price(foodHavenPrice);
    r[0].add_coupan_codes(foodHavencoupan);
    r[0].display();

    string pixelbitesMenu[6] = {
        "Pizza",
        "Burger",
        "Chicken",
        "Fried Rice",
        "Pasta",
        "Chicken"};

    double pixelbitesPrice[6] = {
        14.99, 6.99, 2.99, 7.99, 21.99, 6.99};
    string pixelbitescoupan[5] = {
        "PB-BOGO-67890", "PB-BOGO-67190", "PB-BOGO-67892", "PB-BOGO-67840", "PB-BOGO-67896"};
    r[1].add_coupan_codes(pixelbitescoupan);
    r[1].add_menu(pixelbitesMenu);
    r[1].add_price(pixelbitesPrice);
    r[1].display();

    bogo b1("FH-BOGO-12345", "27-06-2023", "24-07-2024");
    b1.set(r);

    user u("mohid", 18, "03040506078", 2);
    u.setbogo(b1);
    u.accumalate("FH-BOGO-12345");
    u.redeemed("foodhaven", "FH-BOGO-12345");

    return 0;
}