// Create a C++ class named "Exam" using DMA designed to manage student exam records,
// complete with a shallow copy implementation? Define attributes such as student name, exam
// date, and score within the class, and include methods to set these attributes and display exam
// details. As part of this exercise, intentionally omit the implementation of the copy constructor
// and copy assignment operator. Afterward, create an instance of the "Exam" class, generate a
// shallow copy, and observe any resulting issues?

#include <iostream>
#include <cstring>
using namespace std;

class Exam {
private:
    char* student_name;
    char* examDate;
    float score;

public:
    // Constructor
    Exam(const char* name, const char* date, float sc) {
        int lenght=strlen(name)+1;
        student_name = new char[lenght];
        strcpy(student_name, name);

        examDate = new char[strlen(date) + 1];
        strcpy(examDate, date);

        score = sc;
    }
    void setname(const char*name){
        
     int lenght=strlen(name)+1;
        student_name = new char[lenght];
        strcpy(student_name, name);
    }
    void setdate(const char*date){
 
     int lenght=strlen(date)+1;
        examDate = new char[lenght];
        strcpy(examDate, date);
    }

    // Destructor
    ~Exam() {
        delete[] student_name;
        delete[] examDate;
    }

    void displayDetails() {
        cout << "Student: " << student_name<<endl;
         cout<< "Date: " << examDate<<endl;
         cout << "Score: " << score << endl;
    }
};

int main() {
    Exam exam1("Manahil", "21-11-2025", 95.5);
    cout << "Exam1 details:" << endl;
    exam1.displayDetails();

    // Calling Shallow copy... default 
    Exam exam2 = exam1;
    cout << "\nExam2 details (Shallow Copy):" << endl;
    exam2.displayDetails();
    exam2.setname("ayesha");
    cout<<"\nexam 2 details afterchanging name:"<<endl;
    exam2.displayDetails();
    cout<<"\nexam 1 details after changing name of exam 2:"<<endl;
    exam1.displayDetails();
    // Both exam1 and exam2 share the same memory address. 
// Therefore, changing the name in exam2 also changes it in exam1. 
// This happens because of shallow copy. 

    // When program ends, both exam1 and exam2 destructors
    // will try to delete the SAME memory, leading to runtime issues.

    return 0;
}
