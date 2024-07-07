// #include<iostream>
// using namespace std;
// template<typename t>

// void print(t x)
// {
//     cout<<x<<endl;

// }

// int main()
// {
//     print<int>(10);
//     print<double>(10.5);
//     print<char>('a');
//     return 0;
// }


// #include<iostream>
// using namespace std;
// template<typename x ,typename y>
// void print(x a,y b)
// {
//     cout<<a<<"\t";
//     cout<<b<<endl;
// }
// int main()
// {
//     print(10,10.5);
//     print(10,"hello world");
//     print(10.0,"hello world");
   
// return 0;
// }

// #include<iostream>
// using namespace std;
// template<class t>

// class calculator
// {
//     t a;
//     t b;
//     public:
//     calculator(t a,t b)
//     {
//         this->a=a;
//         this->b=b;
//     }
//     void display()
//     {
//         cout<<add()<<endl;
//         cout<<sub()<<endl;
//         cout<<mul()<<endl;
//         cout<<div()<<endl;
//     }
//     t add()
//     {
//         return a+b;
//     }
//     t sub()
//     {
//         return a-b;
//     }
//     t mul()
//     {
//         return a*b;
//     }
//     t div()
//     {
//         try
//         {
//             if(b==0)
//             {
//                 throw runtime_error("Invalid");
//             }
//             else
//             {
//                 return a/b;
//             }
//         }
//         catch(exception& e)
//         {
//             cout<<e.what()<<endl;
            
//         }
        
       
//     }

// };
// int main()
// {
//     calculator<int>cal(20,0);
//     cal.display();
//     calculator<int>calint(20,5);
//     calint.display();
// return 0;
// }

// #include<iostream>
// using namespace std;
// template<typename t>

// class matrix
// {
//     int rol;
//     int col;
//     t **arr;
//     public:
//     matrix(int rol,int col)
//     {
//         this->rol=rol;
//         this->col=col;
//         arr=new t*[rol];
//         for(int i=0;i<rol;i++)
//         {
//             arr[i]=new t[col];
//         }
//     }
//     void input()
//     {
//         cout<<"enter value:"<<endl;
//         for(int i=0;i<rol;i++)
//         {
//             for(int j=0;j<col;j++)
//             {
                
//                 cin>>arr[i][j];
//             }
//         }
//     }
//     void display()
//     {
//         for(int i=0;i<rol;i++)
//         {
//             for(int j=0;j<col;j++)
//             {
//                 cout<<arr[i][j]<<"\t";
//             }
//             cout<<endl;
//         }
//     }
//     matrix<t> operator+(matrix<t> &m)
//     {
//         matrix<t>temp(rol,col);
//         for(int i=0;i<rol;i++)
//         {
//             for(int j=0;j<col;j++)
//             {
//                 temp.arr[i][j]=arr[i][j]+m.arr[i][j];
//             }
//         }
//         return temp;
//     }
//     matrix<t> operator-(matrix<t> &m)
//     {
//         matrix<t>temp(rol,col);
//         for(int i=0;i<rol;i++)
//         {
//             for(int j=0;j<col;j++)
//             {
//                 temp.arr[i][j]=arr[i][j]-m.arr[i][j];
//             }
//         }
//         return temp;
//     }
//     matrix<t> operator*(matrix<t> &m)
//     {
//         matrix<t>temp(rol,col);
//         for(int i=0;i<rol;i++)
//         {
//             for(int j=0;j<col;j++)
//             {
//                for(int k=0;k<col;k++)
//                {
//                 temp.arr[i][j]+=arr[i][k]*m.arr[k][j];
//                }
//             }
//         }
//         return temp;
//     }
// };
// int main()
// {
//     matrix<int>mat(3,3);
//     mat.input();
//     mat.display();
//     matrix<int>mat1(3,3);
//     mat1.input();
//     mat1.display();

//     cout<<endl;
//     matrix<int>mat2(3,3);
//     mat2=mat+mat1;
//     mat2.display();

//     cout<<endl;
//     matrix<int>mat3(3,3);
//     mat3=mat-mat1;
//     mat3.display();

//     cout<<endl;
//     matrix<int>mat4(3,3);
//     mat4=mat*mat1;
//     mat4.display();

    
// return 0;
// }

// #include<iostream>
// using namespace std;
// template<class t>
// class calculator
// {
//     t x;
//     t y;
//     public:
//     calculator(t x,t y)
//     {
//         this->x=x;
//         this->y=y;
//     }
//     void display()
//     {
//         cout<<add()<<endl;
//         cout<<sub()<<endl;
//         cout<<mul()<<endl;
//         cout<<div()<<endl;
//     }
//     t add()
//     {
//         return x+y;
//     }
//     t sub()
//     {
//         return x-y;
//     }
//     t mul()
//     {
//         return x*y;
//     }
//     t div()
//     {
//         try
//         {
//             if(y==0)
//             {
//                 throw runtime_error("Invalid");
//             }
//             else
//             {
//                 return x/y;
//             }
//         }
//         catch(exception &e)
//         {
//             cout<<e.what()<<endl;
//             return 0;
//         }
//     }
// };
// int main()
// {
//     calculator<int>cal(20,0);
//     cal.display();
//     calculator<int>calint(20,5);
//     calint.display();
// return 0;
// }


#include<iostream>
#include<fstream>
using namespace std;

template <typename t>
void check(int n,t arr[])
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                swap(arr[i],arr[j]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
    check(n,arr);

    ofstream fout;
    fout.open("array.txt");
    for(int i=0;i<n;i++)
    {
        fout<<arr[i]<<endl;
    }
return 0;
}
