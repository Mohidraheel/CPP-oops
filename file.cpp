// #include <iostream>
// #include <fstream>
// using namespace std;
// class book
// {
//     int price;
//     string name;
//     string author;

// public:
//     void setinfo()
//     {
//         cout << "Enter the price of the book: ";
//         cin >> price;
//         cin.ignore();
//         cout << "Enter the name of the book: ";
//         getline(cin, name);
//         cout << "Enter the author of the book: ";
//         getline(cin, author);
//     }
//     void show()
//     {
//         cout << "The price of the book is: " << price << endl;
//         cout << "The name of the book is: " << name << endl;
//         cout << "The author of the book is: " << author << endl;
//     }
//     void storinfo()
//     {
//         ofstream fout;
//         fout.open("book.txt");
//         fout.write((char *)this, sizeof(*this));
//         fout<<endl;
//         fout.close();
//     }
//     void readinfo()
//     {
//         ifstream fin("book.txt");
//         if (!fin.is_open())
//         {
//             cout << "Error opening file!" << endl;
//             return;
//         }

//         fin.read((char *)this, sizeof(*this));
//         fin.ignore();
//         fin.read((char *)this, sizeof(*this));
//         fin.read((char *)this, sizeof(*this));


//         show(); // Display the book information
//         fin.close();
//     }
// };
// int main()
// {
//     book b;
//     b.setinfo();
//     b.storinfo();
//     b.readinfo();

//     return 0;
// }


#include<iostream>
#include<fstream>
using namespace std;
class student
{
    int rollno;
    string name;
    float marks;
    char grade;
    public:
    student()
    {
        rollno=0;
        name=" ";
        marks=0;
        grade=' ';
    }
    void getdata()
    {
        cout<<"Enter the rollno: ";
        cin>>rollno;
        cin.ignore();
        cout<<"Enter the name: ";
        getline(cin,name);
        cout<<"Enter the marks: ";
        cin>>marks;
        cin.ignore();
        if(marks>=90)
        {
            grade='A';
        }
        else if(marks>=80)
        {
            grade='B';
        }
        else if(marks>=70)
        {
            grade='C';
        }
        else if(marks>=60)
        {
            grade='D';
        }

    }
    string getname()
    {
        return name;
    }
    int getroll()
    {
        return rollno;
    }

    float getmarks()
    {
        return marks;
    }
    char getgrade()
    {
        return grade;
    }
};
int main()
{
    student s;
    s.getdata();

    ofstream fout;
    fout.open("student.txt");
    fout<<s.getroll()<<endl;
    fout<<s.getname()<<endl;
    fout<<s.getmarks()<<endl;
    fout<<s.getgrade()<<endl;
    fout.close();

    ifstream fin;
    fin.open("student.txt");
    // int r;
    // string n;
    // float m;
    // char g;
    // int r1;
    // cout<<"enter roll number"<<endl;
    // cin>>r1;
    // fin>>r;
    // if(r=r1)
    // {
    //     fin>>n;
    //     fin>>m;
    //     fin>>g;
    //     cout<<r<<endl;
    //     cout<<n<<endl;
    //     cout<<m<<endl;
    //     cout<<g<<endl;
    // }

    int r;
        string n;
        float m;
        char g;    
    while( (fin >> r >> n >> m >> g))
{
    cout << r << endl;
    cout << n << endl;
    cout << m << endl;
    cout << g << endl;
}

    
        

    
     

    
    
    
return 0;
}

