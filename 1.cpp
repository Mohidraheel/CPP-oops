#include <iostream>
#include <string.h>
using namespace std;

class Pet
{
    string name;
    string health_status;
    int hunger_level;
    int happiness_level;
    string special_skills[5];
    int num_skills;
    int available;

public:
    Pet()
    {
        name = "";
        health_status = "";
        hunger_level = 0;
        happiness_level = 0;
    }

    

    void set_name(string n)
    {
        name = n;
    }

    void add_skills(int n, string skills[])
    {
        num_skills=n;
        for (int i = 0; i < n; i++)
        {
            special_skills[i] = skills[i];
        }
    }

    void update_health_status(string new_health)
    {
        health_status = new_health;
    }

    void update_hunger_level(int m)
    {
        hunger_level = m;
    }
    void update_happiness_level(int m)
    {
        happiness_level = m;
        if (get_hunger_level() < 5)
        {
            happiness_level += 1;
        }
        else
        {
            happiness_level -= 1;
        }
    }
    void set_available(int m)
    {
        available = m;
    }

    int get_available( )
    {
        return available;
    }

    string skills()
    {
       
        return special_skills[num_skills];
            
    }

    

    string get_name()
    {
        return name;
    }

    string get_health_status()
    {
        return health_status;
    }

    int get_hunger_level()
    {
        return hunger_level;
    }

    int get_happiness_level()
    {
        return happiness_level;
    }

    void display(int n)
    {
        cout << "Name: " << get_name() <<" (MOHID RAHEEL KHAN 23K-3000)"<<endl;
        cout << "Health Status: " << get_health_status() << endl;
        cout << "Hunger Level: " << get_hunger_level() << endl;
        cout << "Happiness Level: " << get_happiness_level() << endl;
        if (get_happiness_level() < 5)
        {
            cout << get_name() << " is happy"<<endl;
        }
        else
        {
            cout << get_name() << " is sad"<<endl;
        }
        cout << "Special Skills: ";
        for (int i = 0; i < n; i++)
        {
            cout << special_skills[i] << endl;
            
        }
        if(get_available()==0)
        {
           cout<<"pet is now available"<<endl;
        }
        else
        {
            cout<<"pet is not available for adoption"<<endl;
        }
        
        cout << endl;
    }

    void display_skills()
    {
        
        for (int i = 0; i < num_skills; i++)
        {
            cout << special_skills[i] << endl;
            
        }
        cout << endl;
    }
};

class adopt
{
    string name;
    string mobile_num;
    Pet adopted_pet;

public:
    adopt()
    {
        name = "";
        mobile_num = "";
    }

    void set_name(string n)
    {
        name = n;
    }

    void set_mobile_num(string n)
    {
        mobile_num = n;
    }

    void adopt_pet(Pet adopted_pet)
    { 
        
        this->adopted_pet=adopted_pet;

    }
    void display()
    {
        cout<<"adopted pet name:"<<adopted_pet.get_name()<<endl;
        cout<<"pet adopted by :"<<name<<endl;
        cout<<"mobile number:"<<mobile_num<<endl;
        cout<<"health status:"<<adopted_pet.get_health_status()<<endl;
        cout<<"hunger level:"<<adopted_pet.get_hunger_level()<<endl;
        cout<<"happiness level:"<<adopted_pet.get_happiness_level()<<endl;
        cout<<"special skills:"<<endl;
        adopted_pet.display_skills();
        
    }

    void return_pet()
    {
        string name;
        int m;
        cout<<"enter a name you want to return: ";
        getline(cin,name);
            if(adopted_pet.get_name()==name)
            {
                adopted_pet.get_name()=="";
                cout<<"pet returned: "<<endl;
                m=0;
                adopted_pet.set_available(m);
                adopted_pet.display(3);
            }
            else
            {
                cout<<"pet not found"<<endl;
            }
        
    }


};

int main()
{
    Pet pet;
    Pet pet2;

    pet.set_name("cat");
    string skills[3] = {"Fetch", "sweet", "Sleep"};
    pet.add_skills(3, skills);

    pet.update_health_status("weak");
    pet.update_hunger_level(4);// 5 is medium less 5 more hungry
    pet.update_happiness_level(7);
    pet.set_available(0);

    pet2.set_name("dog");
    string skills1[5] = {"Fetch", "Bark", "Sleep","fast running","trained"};
    pet2.add_skills(5, skills1);
    

    pet2.update_health_status("strong");
    pet2.update_hunger_level(8);
    pet2.update_happiness_level(5);
    pet2.set_available(1);
    

     cout<<"pet 1"<<endl;
     pet.display(3);
     cout<<"pet 2"<<endl;
     pet2.display(5);
    

    adopt adopter1;
    adopter1.set_name("mohid");
    adopter1.set_mobile_num("0377777777");
    adopter1.adopt_pet(pet);
    adopter1.display();
    adopter1.return_pet();


    return 0;
}
