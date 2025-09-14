//  Write a program to implement the Bubble Sort algorithm. The program should take
// an array of integers as input from the user, sort the array using bubble sort, and then
// display both the unsorted and sorted arrays.
#include <iostream>
using namespace std;
int main(){
    int* arr;
    int n;
    cout<<"enter the number of element you want to insert: "<<endl;
    cin>>n;
    arr=new int[n];
    for(int i=0 ;i<n ;i++){
        cout<<"Enter "<<i+1<<" element."<<endl;
        cin>>arr[i];
    }
     cout<<"array:"<<endl;
    for(int i=0 ;i<n ;i++){
       cout<<arr[i]<<" ";
    }

    bool check;

    for(int i=0;i<n-1;i++){
       check=true;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                check=false;
            }
        }
        if(check){break;}
    }
    cout<<endl;
    cout<<"sorted array:"<<endl;
    for(int i=0 ;i<n ;i++){
       cout<<arr[i]<<" ";
    }
    delete[] arr;
    return 0;
}