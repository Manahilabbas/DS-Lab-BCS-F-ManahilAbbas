//  Implement the Interpolation Search algorithm. The program should take a sorted array
// with uniformly distributed values and a target value from the user. The algorithm should
// estimate the position of the target and check if the estimated position holds the correct
// value. If the element is found, print its index; otherwise, indicate that it's not present.
#include <iostream>
using namespace std;
int interpolationSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        int pos = low + ((high - low) / (arr[high] - arr[low])) * (key - arr[low]);
        if (arr[pos] == key)
            return pos;
        if (arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
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
    int target;
    cout<<"\nenter target";
    cin>>target;
    int res=interpolationSearch(arr,n,target);
    if(res==-1){cout<<"target not present";}
    else cout<<"Target is at index "<<res;
    return 0;
}