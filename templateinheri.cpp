#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i;
    int a[n];
    cout<<"Enter:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int sum=0;
    for(i=0;i<n;i++)
    {
        try
        {
            if(a[i]>5)
            {
                throw out_of_range("Invalid");
            }
            else
            {
                sum+=a[i];
            }
            
        }
        catch(out_of_range & e)
        {
            cout<< e.what() <<"at index:" <<i<<'\n';
        }
        
    }
    cout<<"Sum:"<<sum<<endl;
return 0;
}
