// Implement a Safe Pointer class to wrap around an integer pointer.
// => Provide methods for setValue(), getValue(), and release().
// =>
// Demonstrate the class by storing marks of 5 students and printing them safely without
// direct pointer manipulation. 
#include<iostream>
using namespace std;
class SafePointer{
    int* marks;
    public:
    SafePointer() {
        marks = new int;  // allocate memory for one int
        *marks = 0;       // initialize
    }
    SafePointer(SafePointer &p){
        marks=new int;
       *(this->marks)=*(p.marks);
    }
    ~SafePointer(){
        delete marks;
        marks=nullptr;
     }

     void setValue(const int a){*marks=a;}
     int getValue(){return *marks;}
     void Realease(){
        if(marks){
            delete marks; 
            marks=nullptr;}
     }
};
 int main(){
    SafePointer student[5];
    for(int i=0;i<5;i++){
        cout<<"give the marks for student "<<i+1<<endl;
        int mark;
        cin>>mark;
        student[i].setValue(mark);
    }
    for(int i=0;i<5;i++){
        cout<<"the marks for student "<<i+1<<"is: ";
      
        cout<<student[i].getValue()<<endl;
    }
    return 0;
 }