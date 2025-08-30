//  Design a program to handle marks of students in different courses using a jagged array
// (since each student is enrolled in a different number of courses).
// => Input the number of courses each student takes.
// => Dynamically allocate memory for each student accordingly.
// => Calculate and display each student’s average marks.
#include <iostream>
 using namespace std;

 int main(){
   
    int nstudent;//rows
    int**students;
    int *indexCourses;
   
   cout<<"enter the number of students"<<endl;
   cin>>nstudent;
   students=new int*[nstudent];
   indexCourses=new int[nstudent];
   for(int i=0;i<nstudent;i++){
     int nCourses;//columns
   cout<<"enter the number of courses for student "<<i+1<<endl;
    cin>>nCourses;
    indexCourses[i]=nCourses;
    students[i]=new int [nCourses];
     }

     for(int i=0;i<nstudent;i++){
        cout<<"\nenter the marks for student "<<i+1<<"for "<<indexCourses[i]<< "courses"<<endl;
        for(int j=0;j<indexCourses[i];j++){
            cout<<"enter marks for course: "<<j+1<<endl;
            cin>>students[i][j];
        }
     }
     
     for(int i=0;i<nstudent;i++){
        float avg=0;
        cout<<"\n the marks for student"<<i+1<<" for "<<indexCourses[i]<< " courses are"<<endl;
        for(int j=0;j<indexCourses[i];j++){
            cout<<" marks for course "<<j+1<<":";
            cout<<students[i][j]<<endl;
            avg+=students[i][j];   
        }
        avg=avg/indexCourses[i];
        cout<<"average marks of student"<<i+1<< " is "<<avg;
     }
     for(int i=nstudent-1;i<0;i--){
        delete[] students[i];
        
     }
     delete[] students;
     delete[] indexCourses;

    return 0;
 }