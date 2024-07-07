#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> hello = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    hello.push_front(1);
    for (auto i = hello.begin(); i != hello.end();)
    {
        cout << *i << endl;
        i++;
    }
    hello.unique();
    for (auto i = hello.begin(); i != hello.end();)
    {
        cout << *i << endl;
        i++;
    }
    return 0;
}
