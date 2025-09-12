#include <iostream>
using namespace std;

int main() {
    int n,target;
    cout << "how many elements you want to enter?"<<endl;
    cin >> n;
    int *arr=new int[n];
    
    for (int i = 0; i < n; i++){
        cout << "Enter array elements "<<i+1<<endl;
        cin >> arr[i];}

    cout << "Enter target value";
    cin >> target;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            cout << "Target found at index " << i << endl;
            found = true;
            return 0;
        }
    }
    if (found==false)
        cout << "Target not found in array." << endl;

    return 0;
}

