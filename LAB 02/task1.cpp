// Implement a program that dynamically allocates a 1D array of integers.
// => The size should be given by the user.
// => Initialize all elements with zero.
// => Then, let the user update values at different positions.
// => Finally, print the array and deallocate memory properly.
#include <iostream>
using namespace std;
int main() {
    int *arr;
    int size;
    cout <<"enter the size of array"<<endl;
    cin>>size;
    arr=new int[size];
    for (int i=0;i<size;i++){
        arr[i]=0;
    }
    
    cout<<"do you want to update any number \n y for yes \n n for no"<<endl;
    char choice ;
    cin>>choice; 
    do{
      if(choice=='y'){
        cout<<"enter the position you eant to update"<<endl;
        int index;
        cin>> index;
           if(index<0||index>size+1){
            cout<<"boundry error!"<<endl;
            return 0;
        }
        cout<<"enter the value"<<endl;
        int value;
        cin>>value;
        arr[index-1]=value;
    }
cout<<"do you want to update any other number \n y for yes \n n for no"<<endl;
cin>>choice; }
while(choice=='y');
    for (int i=0;i<size;i++){
        cout<<i+1<<". "<<arr[i]<<endl;
    }


    return 0;

}
