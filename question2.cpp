
#include <iostream>
using namespace std;
class player
{
protected:
    int player_id;
    string player_name;
    int health;

public:
    player(int player_id, string player_name)
    {
        this->player_id = player_id;
        this->player_name = player_name;
        this->health = 100;
    }
    string get_player_name()
    {
        return player_name;
    }
    int get_player_id()
    {
        return player_id;
    }
    int get_health()
    {
        return health;
    }
    void sethealth(int health)
    {
        this->health = health;
    }

    void displayplayer()
    {
        cout << "Player ID: " << player_id << endl;
        cout << "Player Name: " << player_name << endl;
        cout << "Health: " << health << endl;
    }
};
class weapon
{
    string weapon_list[100];
    int count;

public:
    weapon(string w[], int count)
    {
        this->count = count;
        if (count >= 5)
        {
            for (int i = 0; i < count; i++)
            {
                weapon_list[i] = w[i];
            }
        }
        else
        {
            cout << "Not enough weapons" << endl;
        }
    }

    void use()
    {
        string choice;
        cout << "Which weapon do you want to use? " << endl;
        for (int i = 0; i < count; i++)
        {
            cout << weapon_list[i] << endl;
        }
        cin >> choice;
        for (int i = 0; i < count; i++)
        {
            if (choice == weapon_list[i])
            {
                cout << "weapon used " << weapon_list[i] << endl;
                break;
            }
        }
    }
};

class character : public player
{
    int level;
    string experience;
    int points;

public:
    character(int player_id, string player_name) : player(player_id, player_name)
    {
        level = 0;
        experience = "Beginner";
        points = 0;
    }
    void levelUp()
    {
        points += 10;
        if (points >= 10)
        {
            level++;
            if (experience == "Beginner")
                experience = "Intermediate";
            else if (experience == "Intermediate")
                experience = "Advanced";
            else if (experience == "Advanced")
                experience = "Expert";
        }
        cout << "Level: " << level << endl;
        cout << "Experience: " << experience << endl;
    }
    void dechealth(int amount)
    {
        player::sethealth(player::get_health() - amount);
    }
    void playgame(weapon &w)
    {
        cout<<"game is starting"<<endl;
        displayplayer();
        w.use();
        cout << "Enemy has been attacked" << endl;
        dechealth(5);
        levelUp();
    }
};
class enemy
{
    int damage;

public:
    enemy(int damage)
    {
        if (damage >= 1 && damage <= 10)
        {
            this->damage = damage;
        }
        else
        {
            cout << "Damage must be between 1 and 10" << endl;
        }
    }
    void attack(character &c, weapon &w)
    {
        cout<<"enemy"<<endl;
        w.use();
        cout << "You have been attacked" << endl;
        c.dechealth(damage);
    }
};
int main()
{
    cout<<"Mohid Raheel Khan"<<endl;
    string w[6] = {
        "Knife","Sword","Axe","Bow","M416","REVOLVER"};
    weapon w1(w, 6);
    character c2(3000, "Mohid");
    enemy e(10);

    c2.playgame(w1);
    e.attack(c2, w1);
    cout<<endl;
    cout<<endl;

    c2.playgame(w1);
    cout<<endl;
    c2.playgame(w1);
    cout<<endl;
    c2.playgame(w1);   


    return 0;
}
