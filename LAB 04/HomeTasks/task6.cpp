// Implement the Comb Sort algorithm to sort an array of integers. This algorithm improves
// upon bubble sort by reducing the number of comparisons and swaps using a "gap" that
// decreases over time. After sorting, perform a complexity analysis: count and display the
// total number of swaps and comparisons performed during the sorting process.
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
    float shrink = 1.3;  
    int gap = n;       
    bool swapped = true;
    int swaps=0,camp=0;

    while (gap > 1 || swapped) {
        gap = (int)(gap / shrink);
        if (gap < 1) {
            gap = 1; 
        }

        swapped = false;

        for (int i = 0; i + gap < n; ++i) {
            camp++;
            if (arr[i] > arr[i + gap]) {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swaps++;
                swapped = true;
            }
        }
    }
     cout<<"\nsorted array:"<<endl;
    for(int i=0 ;i<n ;i++){
       cout<<arr[i]<<" ";
    }
     cout << "\n\nNumber of comparisons: " << camp << endl;
    cout << "Number of swaps: " << swaps << endl;
    delete[] arr;
    return 0;
}