//#include <iostream>
//#include <string>
//
//class Author {
//public:
//    std::string authorName;
//    int authorID;
//
//    Author(std::string name, int id) : authorName(name), authorID(id) {}
//};
//
//class Book {
//public:
//    std::string title;
//    std::string ISBN;
//    int year;
//    Author* author; // Association with Author class
//
//    Book(std::string bookTitle, std::string bookISBN, int bookYear, Author* bookAuthor)
//        : title(bookTitle), ISBN(bookISBN), year(bookYear), author(bookAuthor) {}
//};
//
//int main() {
//    // Creating an Author
//    Author* johnDoe = new Author("John Doe", 123);
//
//    // Creating a Book associated with the Author
//    Book* sampleBook = new Book("Sample Book", "ISBN123", 2022, johnDoe);
//
//    // Accessing Author information through Book
//    std::cout << "Book Title: " << sampleBook->title << std::endl;
//    std::cout << "Author: " << sampleBook->author->authorName << std::endl;
//
//    // Remember to free the allocated memory
//    delete johnDoe;
//    delete sampleBook;
//
//    return 0;
//}





//Example two:
#include <iostream>
#include <string>

const int MAX_STUDENTS = 10;
const int MAX_COURSES = 5;

class Student;

class Course {
public:
    std::string courseName;
    int courseCode;
    Student* enrolledStudents[MAX_STUDENTS];  // Association with Student class
    int numEnrolledStudents;

    Course(std::string name, int code) : courseName(name), courseCode(code), numEnrolledStudents(0) {}

    // Method to enroll a student in the course
    void enrollStudent(Student* student) {
        if (numEnrolledStudents < MAX_STUDENTS) {
            enrolledStudents[numEnrolledStudents++] = student;
        } else {
            std::cout << "Course is full. Cannot enroll more students." << std::endl;
        }
    }
};

class Student {
public:
    std::string studentName;
    int studentID;
    Course* enrolledCourses[MAX_COURSES];  // Association with Course class
    int numEnrolledCourses;

    Student(std::string name, int id) : studentName(name), studentID(id), numEnrolledCourses(0) {}

    // Method to enroll in a course
    void enrollInCourse(Course* course) {
        if (numEnrolledCourses < MAX_COURSES) {
            enrolledCourses[numEnrolledCourses++] = course;
            course->enrollStudent(this);  // Enroll the student in the course
        } else {
            std::cout << "Student is already enrolled in the maximum number of courses." << std::endl;
        }
    }
};

int main() {
    // Creating instances of Course
    Course* mathCourse = new Course("Mathematics", 101);
    Course* physicsCourse = new Course("Physics", 201);

    // Creating instances of Student
    Student* alice = new Student("Alice", 1);
    Student* bob = new Student("Bob", 2);

    // Enrolling students in courses
    alice->enrollInCourse(mathCourse);
    bob->enrollInCourse(mathCourse);
    bob->enrollInCourse(physicsCourse);

    // Accessing enrolled students in a course
    std::cout << "Students enrolled in the Mathematics course:" << std::endl;
    for (int i = 0; i < mathCourse->numEnrolledStudents; ++i) {
        std::cout << "- " << mathCourse->enrolledStudents[i]->studentName << std::endl;
    }

    // Accessing enrolled courses for a student
    std::cout << "\nCourses enrolled by Bob:" << std::endl;
    for (int i = 0; i < bob->numEnrolledCourses; ++i) {
        std::cout << "- " << bob->enrolledCourses[i]->courseName << std::endl;
    }

    // Remember to free the allocated memory
    delete mathCourse;
    delete physicsCourse;
    delete alice;
    delete bob;

    return 0;
}

	