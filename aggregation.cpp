// #include <iostream>
// using namespace std;
// class students
// {
//     string name;
//     string roll_number;
//     int marks;

// public:
//     students(string name, string roll_number, int marks)
//     {
//         this->name = name;
//         this->roll_number = roll_number;
//         this->marks = marks;
//     }
//     string get_name()
//     {
//         return name;
//     }
//     int get_marks()
//     {
//         return marks;
//     }
//     void display()
//     {
//         cout << name << endl;
//         cout << roll_number << endl;
//         cout << marks << endl;
//     }
// };

// class department
// {
//     string course;
//     double avg;
//     int count;

//   public:
//   students *std[5];
//     department(string course)
//     {
//         this->course = course;
//         count=0;
//     }
//     void set_avg()
//     {
//         double sum = 0;
//         for (int i = 0; i < 5; i++)
//         {
//             sum = sum + std[i]->get_marks();
//         }
//         avg = sum / 5;
//     }
//     void add(students *s)
//     {
//         std[count] = s;
//         count++;
//     }

//     void checkhighest()
//     {

//         int max=0;
//         int max2=0;
//         for (int i = 0; i <5; i++)
//         {
//             if(std[i]->get_marks() > max)
//             {

//                 max2 = i;
//                 max = std[i]->get_marks();
//             }
//         }
//         for(int i = 0; i < 5; i++)
//         {
//             if(i==max2)
//             {
//                 cout<<"name: "<<std[i]->get_name()<<endl;
//                 cout<<"highest marks:" << std[i]->get_marks() << endl;
//             }
//         }

//     }
//     void displaym()
//     {

//         cout << course << endl;
//         cout << avg << endl;
//         checkhighest();

//     }

// };
// int main()
// {
//     students *std =new students[5] {
//     students("mohid", "23k-3000", 50),
//     students("hassan", "23k-0625", 40),
//     students("hani", "23k-7000", 30),
//     students("basit", "23k-9400", 46),
//     students("shayan", "23k-300", 35)

//     };

//      department d("object oriented Programming");
//        for (int i = 0; i < 5; i++)
//     {
//         d.add(&std[i]);
//     }
//     for (int i = 0; i < 5; i++)
//     {
//         d.std[i]->display();
//     }
//     d.set_avg();
//     d.displaym();

//     return 0;
// }

#include <iostream>
using namespace std;
class department;
class student
{
    int marks;
    string name;
    int count;

public:
    department *d[5];
    student(string name, int marks)
    {
        this->name = name;
        this->marks = marks;
        count = 0;
    }
    void display()
    {
        cout << name << endl;
        cout << marks << endl;
    }
    int get_marks()
    {
        return marks;
    }
    string get_name()
    {
        return name;
    }
    void addcourse(department *d);
   
    void display3();
    
};

class department
{
    int count;
    string coursename;
    string courseteacher;
    double avg;

public:
    student *std[5];
    department(string coursename, string courseteacher)
    {
        this->coursename = coursename;
        this->courseteacher = courseteacher;
        count = 0;
    }
    void add(student *s)
    {
        if (count < 6)
        {
            std[count] = s;
            count++;
        }
    }
    void remove(string name)
    {
        for (int i = 0; i < count; i++)
        {
            if (name == std[i]->get_name())
            {

                for (int j = 0; j < count; j++)
                {
                    std[j] = std[j + 1];
                }
                count--;
                break;
            }
        }
    }
    string get_coursename()
    {
        return coursename;
    }
    void display()
    {
        cout << coursename << endl;
        cout << courseteacher << endl;

        cout << "students enrolled:" << endl;
        for (int i = 0; i < count; i++)
        {
            std[i]->display();
        }
    }
};
void student::addcourse(department *d) {
    this->d[count] = d;
    count++;
}

void student::display3() {
    cout << name << endl;
    cout << marks << endl;

    cout << "courses enrolled" << endl;
    for (int i = 0; i < count; i++) {
        cout << d[i]->get_coursename() << endl;
    }
}
int main()
{
    student *s = new student[5]{
        student("mohid", 50),
        student("hassan", 40),
        student("hani", 30),
        student("basit", 46),
        student("shayan", 35)};
    department d("object oriented Programming", "Sir Basit");
    for (int i = 0; i < 5; i++)
    {
        d.add(&s[i]);
    }

    s[0].addcourse(&d);
    s[0].display3();
    d.remove("mohid");
    d.display();

    return 0;
}
