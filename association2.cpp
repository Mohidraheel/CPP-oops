#include<iostream>
#include<string>

using namespace std;

class student;

class course {
    string course_name;
    int course_id;
    student *students[10]; // Array of pointers to students
    int num_of_students;
public:
    course(string course_name, int course_id) : course_name(course_name), course_id(course_id), num_of_students(0) {}

    void add_student(student* s) {
        if (num_of_students < 10) {
            students[num_of_students++] = s; 
            s->enroll(this);// Change this line
        } else {
            cout << "Maximum students limit reached for course " << course_name << endl;
        }
    }

    void display() const {
        cout << "Course name: " << course_name << endl;
        cout << "Course ID: " << course_id << endl;
        cout << "Number of students: " << num_of_students << endl;
        for (int i = 0; i < num_of_students; ++i) {
            cout << "Student enrolled: " << students[i]->get_name() << endl;
        }
    }

    string get_course_name() const {
        return course_name;
    }

    friend class student;
};

class student {
    string name;
    int id;
    course* courses[5]; // Array of pointers to courses
    int num_of_courses;
public:
    student(string name, int id) : name(name), id(id), num_of_courses(0) {}
    
    string get_name() const {
        return name;
    }

    void enroll(course* c) {
        if (num_of_courses < 5) {
            courses[num_of_courses++] = c;
             // Change this line
        } else {
            cout << "Maximum courses limit reached for student " << name << endl;
        }
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Number of courses: " << num_of_courses << endl;
        for (int i = 0; i < num_of_courses; ++i) {
            cout << "Course enrolled: " << courses[i]->get_course_name() << endl;
        }
    }

    friend class course;
};

int main() {
    course *maths=new course("calculus",101);
    course *biology=new course("biology",102);

    student *mohid=new student("mohid",3000);
    student *mohamed=new student("mohamed",3001);

    mohid->enroll(maths);
    mohamed->enroll(maths);
    mohid->enroll(biology);

    maths->display();
    biology->display();

    mohid->display();
    mohamed->display();

    return 0;
}