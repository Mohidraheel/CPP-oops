#include <iostream>
using namespace std;
class security_tool
{
protected:
    string security_level;
    int numofdevices;
    double cost;

public:
    security_tool(string s, int n, double c)
    {
        numofdevices = n;
       
        if(s=="high"||s=="medium"||s=="low")
        {
             security_level = s;
        }
        else
        {
            cout<<"Invalid security level"<<endl;
        }
        cost = c;
        if (c <= 0)
        {
            cout << "wrong cost enter correctly" << endl;
            exit(0);
        }
    }

   virtual void perform_scan()
    {
        cout << "performing scan" << endl;
    }
};

class firewall_security : public security_tool
{
protected:
    int ports[23];
    string protocols[6] = {
        "HTTPS", "FTP", "UDP", "ICMP", "SSH", "SNMP"};

public:
    firewall_security(string s, int n, double c, int student) : security_tool(s, n, c)
    {
        for (int i = 0; i < 23 ; i++)
        {
            ports[i] = student + i;
        }
    }
    void perform_scan() override
    {
        cout << "Performing firewall scan." << endl;
        cout << "Security Level: " <<security_level  << endl;

        cout<<"Allowed protocols: " <<endl;
        for (int i = 0; i < 6; i++)
        {
            cout << protocols[i] << endl;
        }

        if(security_level=="high")
        {
            cout<<"Allowed ports: " <<endl;
            for(int i = 0; i < 23; i++)
            {
               cout<<"ports:"<< " " << ports[i] << endl;
            }
        }
        else
        {
            if(security_level=="medium")
            {
                cout<<"Allowed ports: " <<endl;
                for(int i = 0; i < 23 && i<2; i++)
                {
                   cout<<"ports:"<< " " << ports[i] << endl;
                }
            }
            else
            {
                if(security_level=="low")
                {
                    cout<<"Allowed ports: " <<endl;
                    for(int i = 0; i < 23 && i<5; i++)
                    {
                        cout<<"ports:"<< " " << ports[i] << endl;

                    }
                    cout<<"protocol only supported:DNS AND TCP"<<endl;
                }
                else
                {
                    cout << "wrong security level enter correctly" << endl;
                    exit(0);
                }
            }
        }
    }
};
int main()
{
    cout<<"mohid raheel khan 23k-3000"<<endl;
    firewall_security f("low", 5, 100000, 3);
    f.perform_scan();
    cout<<endl;

    firewall_security f1("medium",10,5000,31);
    f1.perform_scan();
    cout<<endl;

    firewall_security f2("high", 20, 1000000, 10);
    f2.perform_scan();

    return 0;
}
