// #include<iostream>
// using namespace std;
// class a
// {
//     public:
//     void f1()
//     {
//         cout<<"a f1"<<endl;
//     }
//     // virtual void f2()
//     // {
//     //     cout<<"a f2"<<endl;
//     // }
//     virtual void f3()
//     {
//         cout<<"a f3"<<endl;
//     }
//     virtual void f4()
//     {
//         cout<<"a f4"<<endl;
//     }
// };
// class b:public a
// {
//     public:
//      void f1()
//     {
//         cout<<"b f1"<<endl;
//     }
//     void f2()
//     {
//         cout<<"b f2"<<endl;
//     }
//     void f4(int x)
//     {
//         cout<<x;
//     }

// };
// int main()
// {
//     // a obj;
//     // b *b1;
//     // b1=(b*)&obj;
//     // b1->f1();
   
//    a *ptr;
//    b obj;
//    ptr=&obj;
//    ptr->f2();

// return 0;
// }

// #include<iostream>
// using namespace std;
// class b;
// class a
// {
//     int x;
//     public:
//     void setdata(int a)
//     {
//         x=a;
//     }
//     friend void sum(a,b);
//     friend class b;
// };
// class b
// {
//     int y;
//     public:
//     void setdata(int b)
//     {
//         y=b;
//     }
//     void display(a& o1)
//     {
//         cout<<++o1.x;

//     }
//     friend void sum(a,b);
// };
// void sum(a o1,b o2)
// {
//     cout<<o1.x+o2.y<<endl;
// }
// int main()
// {
//     a obj1;
//     b obj2;
//     obj1.setdata(10);
//     obj2.setdata(20);
//     sum(obj1,obj2);
//     obj2.display(obj1);
   

    
// return 0;
// }


// #include<iostream>
// using namespace std;
// class b;
// class c;

// class a
// {
//     int x;
//     public:
//     void setdata(int a)
//     {
//         x=a;
//     }
//     friend void multiplying(a,b,c);
//     friend class c;
// };

// class b
// {
//     int y;
//     public:
//     void setdata(int b)
//     {
//         y=b;
//     }
//     friend void multiplying(a,b,c);
//     friend class c;

// };

// class c
// {
//     int z;
//     public:
//     void setdata(int c)
//     {
//         z=c;
//     }
//     void display(a o1,b o2)
//     {
//         cout<<o1.x<<endl;
//         cout<<o2.y<<endl;
//     }
//     friend void multiplying(a,b,c);
// };

// void multiplying(a o1,b o2,c o3)
// {
//     cout<<o1.x*o2.y*o3.z<<endl;
// }
// int main()
// {
//     a obj1;
//     b obj2;
//     c obj3;
//     obj1.setdata(10);
//     obj2.setdata(20);
//     obj3.setdata(30);
//     multiplying(obj1,obj2,obj3);
//     obj3.display(obj1,obj2);
// return 0;
// }

#include<iostream>
using namespace std;
class b;
class a
{
    int number;
    public:
    friend ostream& operator <<(ostream&out,a const&obj);
    friend istream& operator >>(istream&in,a&obj);
    int getnum()
    {
        return number;
    }
    // bool operator <(a const&obj)
    // {
    //     return (number<obj.number);
    // }
    friend class b;
    friend void add(a,b);
};
class b
{
 int number;
 public:
 friend ostream& operator <<(ostream&out,b const&obj);
 friend istream& operator >>(istream&in,b&obj);
 friend void add(a,b);

 int getnum()
 {
     return number;
 }

 void display(a obj1)
 {
    cout<<obj1.number<<endl;
 }

};

void add(a obj1,b obj2)
{
    int sum;
    sum=obj1.getnum()+obj2.getnum();
    cout<<sum<<endl;

}

ostream& operator <<(ostream&out,a const&obj)
{
    out<<obj.number;
    return out;
}

istream& operator >>(istream&in,a&obj)

{
    in>>obj.number;
    return in;
}
ostream& operator <<(ostream&out,b const&obj)
{
    out<<obj.number;
    return out;
}

istream& operator >>(istream&in,b&obj)

{
    in>>obj.number;
    return in;
}
int main()
{
    a obj1;
    cin>>obj1;
    // cin>>obj2;
    // cout<<obj1<<endl;
    // cout<<obj2<<endl;
    // if(obj1<obj2)
    // {
    //     cout<<"obj1 is less than obj2"<<endl;
    // }
    // else
    // {
    //     cout<<"obj1 is greater than obj2"<<endl;
    // }
    b obj2;
    cin>>obj2;
    cout<<obj1<<endl;
    cout<<obj2<<endl;
    obj2.display(obj1);
    add(obj1,obj2);
    
    
return 0;
}

