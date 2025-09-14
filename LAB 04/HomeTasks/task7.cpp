 // Implement the Shell Sort algorithm to sort an array of integers. The algorithm should start
// with a large gap, then perform a gapped insertion sort, and gradually reduce the gap until
// it's 1. After sorting, compare its performance against the Bubble Sort and Insertion Sort
// algorithms for the same input array size (e.g., 1000 elements). Record and display the time
// taken and the number of comparisons/swaps for all three algorithms to demonstrate why
// Shell Sort is an improvement over Insertion Sort.
#include <iostream>
#include <ctime>
using namespace std;
void shellSort(int myarr[], int n1,int& comp,int&swaps) {
    comp=0;swaps=0;
    for (int gap = n1 / 2; gap > 0; gap /= 2) {
        for (int j = gap; j < n1; j++) {
            int temp = myarr[j];
            int res = j;
            comp++;
            while (res >= gap && myarr[res - gap] > temp) {
                myarr[res] = myarr[res - gap];
                res -= gap;
                swaps++;
            }
            myarr[res] = temp;
        }
    }
}
void bubblesort(int arr[],int n,int& comp,int&swaps){
    bool check;
comp=0;swaps=0;
    for(int i=0;i<n-1;i++){
       check=true;
        for(int j=0;j<n-1-i;j++){
            comp++;
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swaps++;
                check=false;
            }
        }
        if(check){break;}
    }}

void insertionsort(int arr[],int n,int& comp,int&swaps){
    comp=0;swaps=0;
    for(int i=0;i<n;i++){
        int j=i+1;
        comp++;
        while(j>0&&arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
            swaps++;
            j--;
        }
    }
}

int main(){
    int n;
    cout<<"enter the number of element you want to insert: "<<endl;
    cin>>n;
    int* arr1 = new int[n];
    int* arr2 = new int[n];
    int* arr3 = new int[n];
    for(int i=0 ;i<n ;i++){
        cout<<"Enter "<<i+1<<" element."<<endl;
        cin>>arr1[i];
        arr2[i]=arr1[i];
        arr3[i]=arr1[i];
    }
     cout<<"array:"<<endl;
    for(int i=0 ;i<n ;i++){
       cout<<arr1[i]<<" ";
    }

    int comp, swaps;
    clock_t start, end;
    double time_taken;

      start = clock();
    bubblesort(arr1, n, comp, swaps);
    end = clock();
    time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "\nBubble Sort:" << endl;
    cout << "Time taken: " << time_taken << " sec" << endl;
    cout << "Comparisons: " << comp << endl;
    cout << "Swaps: " << swaps << endl;

      start = clock();
    insertionsort(arr2, n, comp, swaps);
    end = clock();
    time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "\nInsertion Sort:" << endl;
    cout << "Time taken: " << time_taken << " sec" << endl;
    cout << "Comparisons: " << comp << endl;
    cout << "Swaps: " << swaps << endl;

      start = clock();
    shellSort(arr3, n, comp, swaps);
    end = clock();
    time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "\nShell Sort:" << endl;
    cout << "Time taken: " << time_taken << " sec" << endl;
    cout << "Comparisons: " << comp << endl;
    cout << "Swaps: " << swaps << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    return 0;
}