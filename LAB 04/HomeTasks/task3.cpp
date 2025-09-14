// Implement the Selection Sort algorithm. The program should take an array of integers from
// the user, find the smallest element, and exchange it with the element at the first position.
// This process should continue until the array is completely sorted. Display the sorted array
// to the user.#include <iostream>
#include<iostream>
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
    int minindex=0;
    int min;
  
    for(int j=0;j<n-1;j++){
         min=INT8_MAX;
    int i=j;
        while(i<n&&arr[i]<min){
            min=arr[i];
            minindex=i;
        i++;}
   
    swap(arr[j],arr[minindex]);
    }
    cout<<"sorted array:"<<endl;
    for(int i=0 ;i<n ;i++){
       cout<<arr[i]<<" ";
    }
    delete[] arr;
    return 0;
}