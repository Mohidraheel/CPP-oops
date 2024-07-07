// #include<iostream>
// using namespace std;

// class practice
// {
//     int x;
//     int y;
    
//     public:
//     practice(int n,int m)
//     {
//         x=n;
//         y=m;
//     }

//     practice operator+(const practice& obj)
//     {
//         x=x+obj.x;
//         y=y+obj.y;
//        return practice(x,y);
//     }
//     friend ostream& operator<<(ostream&, const practice& obj)
//     {
//         cout<<"hello world!"<<endl;
//     }
//     void display()
//     {
//         cout<<x<<" "<<y<<endl;
//     }
// };
// int main()
// {
//     practice obj1(10,11);
//     practice obj2(20,21);
//     obj1=obj1+obj2;
//     obj1.display();
//     cout<<obj1<<endl;
// return 0;
// }

// #include<iostream>
// using namespace std;

// class box
// {
    
//     public:
//     int length;
//     int breadth;
//     int height;
//     void setlength(int l)
//     {
//         length=l;
//     }
//     void setbreadth(int b)
//     {
//         breadth=b;
//     }
//     void setheight(int h)
//     {
//         height=h;
//     }
//     double getarea()
//     {
//         return length*breadth*height;
//     }

//     box operator+(const box&obj)
//     {
//         box b;
//         b.length=length+obj.length;
//         b.breadth=breadth+obj.breadth;
//         b.height=height+obj.height;
//         return b;
//     }
    
//     friend ostream& operator<<(ostream&output, const box& obj);
//     friend istream& operator>>(istream&in,box&obj);
    
// };

// ostream& operator<<(ostream& output, const box& obj)
// {
//     output<<obj.length<<" "<<obj.breadth<<" "<<obj.height;
//     return output;
 
// }
// istream&operator>>(istream&in, box&obj)
// {
//     cout<<"enter length breadth height<<"<<endl;;
//     in>>obj.length>>obj.breadth>>obj.height;
//     return in;
// }
// int main()
// {
//     box b1,b2;
//     b1.setlength(10);
//     b1.setbreadth(20);
//     b1.setheight(30);
//     b2.setlength(20);
//     b2.setbreadth(30);
//     b2.setheight(40);
//     cout<<b1.getarea()<<endl;
//     cout<<b2.getarea()<<endl;
//     box b3;
//     b3=b1+b2;
//     cout<<b3.getarea()<<endl;
//     cout<<b3;

//     box b4;
//     cin>>b4;
//     cout<<b4;
    
// return 0;
// }

// #include <iostream>
// using namespace std;
// class Base {
// public:
//     virtual ~Base() = 0; // Pure virtual destructor
// };

// // Pure virtual destructor without definition
//  Base::~Base(){cout << "base destructor called." << std::endl;}// This line is commented out intentionally

// class Derived : public Base {
// public:
//     ~Derived()  {
//         cout << "Derived destructor called." << std::endl;
//     }
// };

// int main() {
//     Base* obj = new Derived();
//     delete obj;
//     return 0;
// }


// #include <iostream>
// using namespace std;
// class Demo{
// 	public:
// 		virtual void fun()=0;
// 		int value;
// 		int getdata(int a, int b){
// 			value = a;
// 		}
// };

// class D1:public Demo{
// 	public:
// 		int x;
// 	void fun(){
// 		x = value;
// 		cout<<"data is assigned"<< x <<endl;
// 	}
// };
// class D2:public Demo{
// 	public:
// 		int x;
// 	void fun(){
// 		x = value;
// 		cout<<"data is assigned"<< x <<endl;
// 	}
// };

// int main(){
//     Demo d;
// 	D1 obj1;
// 	obj1.getdata(2,3);
// 	obj1.fun();

// 	D2 obj2;
// 	obj2.getdata(10,3);
// 	obj2.fun();
// }

// #include <iostream>

// // Abstract Base Class
// class Shape {
// public:
//     // Constructor for Shape (abstract base class)
//     Shape() {
//         std::cout << "Shape constructor called." << std::endl;
//     }
//     // Pure virtual function for calculating area
//     virtual double calculateArea() const = 0;

//     // Virtual destructor (required for polymorphic deletion)
//     virtual ~Shape() {
//         std::cout << "Shape destructor called." << std::endl;
//     }
// };
// // Derived Class: Rectangle
// class Rectangle : public Shape {
// private:
//     double length;
//     double width;

// public:
//     // Constructor for Rectangle
//     Rectangle(double l, double w) : length(l), width(w) {
//         std::cout << "Rectangle constructor called." << std::endl;
//     }

//     // Implementation of calculateArea for Rectangle
//     double calculateArea() const override {
//         return length * width;
//     }

//     // Destructor for Rectangle
//     ~Rectangle() {
//         std::cout << "Rectangle destructor called." << std::endl;
//     }
// };

// // Use Cases (Main Function)
// int main() {
//     // Create a Rectangle object
//     Rectangle rect(5.0, 3.0);

//     // Call calculateArea() method on Rectangle
//     double area = rect.calculateArea();
//     std::cout << "Area of Rectangle: " << area << std::endl;

//     return 0;
// }


#include <iostream>

// Abstract Base Class
class Shape {
protected:
    double area;

public:
    // Constructor for initializing area
    Shape() : area(0.0) {}

    // Pure virtual function for calculating area
    virtual double calculateArea() = 0;

    // Virtual destructor (required for polymorphic deletion)
    virtual ~Shape() {}
};

// Derived Class: Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Implementation of calculateArea for Rectangle
    double calculateArea() override {
        area = length * width;
        return area;
    }
};

// Derived Class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Implementation of calculateArea for Circle
    double calculateArea() override {
        area = 3.14159 * radius * radius; // Assuming Pi value
        return area;
    }
};

// Use Cases (Main Function)
int main() {
    Shape* shapes[4]; // Array of Shape pointers

    shapes[0] = new Rectangle(5.0, 3.0);
    shapes[1] = new Circle(2.5);
    shapes[2] = new Rectangle(4.0, 4.0);
    shapes[3] = new Circle(3.0);
    // Calculate and display areas
    for (int i = 0; i < 4; ++i) {
        double area = shapes[i]->calculateArea();
        std::cout << "Area of Shape " << i + 1 << ": " << area << std::endl;
    }

    // Clean up
    for (int i = 0; i < 4; ++i) {
        delete shapes[i];
    }

    return 0;
}
