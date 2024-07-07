#include<iostream>
#include<functional>
#include<string>
using namespace std;
int main()
{
    string pass;
    cout<<"enter:"<<endl;
    cin>>pass;

    hash<string>hasher;
    size_t hashvalue=hasher(pass);
    cout<<hashvalue<<endl;
return 0;
}
