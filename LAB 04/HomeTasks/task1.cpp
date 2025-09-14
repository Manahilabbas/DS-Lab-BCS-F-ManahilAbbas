//  Implement a linear search algorithm to find a specific integer in an array. The program
// should take an array of integers and a target value as input from the user. Print the index of
// the target value if it's found or a message indicating that the element is not in the array.
#include <iostream>
using namespace std;
int main(){
    int* arr;
    int n,target;
    cout<<"enter the number of element you want to insert: "<<endl;
    cin>>n;
    arr=new int[n];
    for(int i=0 ;i<n ;i++){
        cout<<"Enter "<<i+1<<" element."<<endl;
        cin>>arr[i];
    }
    cout<<"enter target element: ";
    cin>>target;
    for(int i=0 ;i<n ;i++){
        if(arr[i]==target){
            cout<<"target is at index "<<i<<endl;
        }
    }
delete[] arr;
    return 0;
}