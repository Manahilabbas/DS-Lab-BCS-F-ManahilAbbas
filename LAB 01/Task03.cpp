// Create a C++ class Box that uses dynamic memory allocation for an integer. Implement the
// Rule of Three by defining a destructor, copy constructor, and copy assignment operator.
// Demonstrate the behavior of both shallow and deep copy using test cases.
#include <iostream>
using namespace std;
class shallowbox{
    int* x;
    public:
    shallowbox(int x=0){this->x=new int(x);}
    void setx(int x){*(this->x)=x;}
    void show() const {
        cout << "Value: " << *x << " | Address: " << x << endl;
    }
};
class box {
    int* x;
public:
    box(int val = 0) {
        this->x = new int(val);
    }

    // Copy constructor 
    box(const box& b) {
        this->x = new int(*(b.x));
    }

    // Copy assignment operator 
    box& operator=(const box& b) {
        if (this != &b) {
            delete x;
            this->x = new int(*(b.x));
        }
        return *this;
    }

    // Destructor
    ~box() {
        delete x;
    }

    void setx(int val) { *x = val; }
    void show() const {
        cout << "Value: " << *x << " | Address: " << x << endl;
    }
};
int main(){
    cout<<"Demontrate Shallow copy"<<endl;
    shallowbox b1(10);
    shallowbox b2=b1;
    cout<<"\n b1:"<<endl;
    b1.show();
    cout<<"\n b2:"<<endl;
    b2.show();
    b2.setx(50);
    cout<<"\n b2 after changing value of x :"<<endl;
    b2.show();
    cout<<"\n b1 after changing value of x of b2 :"<<endl;
    b1.show();
   // Since both objects share the same memory address, 
   // a change in one value also changes the other.

cout<<"Demontrate Deep copy"<<endl;
    box b3(100);
    box b4(b3);
    cout<<"\n b3:"<<endl;
    b3.show();
    cout<<"\n b4:"<<endl;
    b4.show();
    b4.setx(50);
    cout<<"\n b4 after changing value of x :"<<endl;
    b4.show();
    cout<<"\n b3 after changing value of x of b4 :"<<endl;
    b3.show();

    // In deep copy, each object has its own memory,
    // so changing one does not affect the other.
   
    return 0;
}
