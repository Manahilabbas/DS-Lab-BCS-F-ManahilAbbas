//  Use Insertion Sort to sort an array of integers provided by the user. Then, implement the
// Binary Search algorithm to find a target value within the newly sorted array. The program
// should display the sorted array and the index of the found element or a message if it's not
// present.
#include <iostream>
using namespace std;
int binarysearch(int f, int l,int target,int arr[]){
    int mid=(f+l)/2;
    if(arr[mid]==target){return mid;}
    if(arr[mid]>target){binarysearch(mid+1,l,target,arr);}
    if(arr[mid]>target){binarysearch(f,mid-1,target,arr);}
    return-1;
}
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
    for(int i=0;i<n;i++){
        int j=i+1;
        while(j>0&&arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
    cout<<"\nsorted array:"<<endl;
    for(int i=0 ;i<n ;i++){
       cout<<arr[i]<<" ";
    }
    int target;
    
    cout<<"\nenter target num: "<<endl;
    cin>>target;
    int index=binarysearch(0,n,target,arr);
    if(index==-1){
        cout<<"taget not exist "<<endl;

    }
    else cout<<"target is at index "<<index;
    delete[] arr;
    return 0;
}