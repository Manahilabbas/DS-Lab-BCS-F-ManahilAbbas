#include <iostream>
#include <string>
using namespace std;

int getPriority(string desig) {
    int priority;
    if (desig=="CEO") priority= 1;
    else if (desig=="CTO") priority= 2;
   else if (desig=="CFO") priority= 3;
    else if (desig=="VP")  priority= 4;
    else if (desig=="MGR") priority= 5;
    else if (desig=="EMP") priority= 6;
    return priority; }
void insertionSort(string arr[], int n) {
    for (int i = 1; i < n; i++) {
        string key = arr[i];
        int j = i - 1;
        while (j >= 0 && getPriority(arr[j]) > getPriority(key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }}
int main() {
    string employees[] = {"EMP", "CFO", "MGR", "EMP", "VP", "CTO", "MGR", "CEO"};
    int n = 8;
    cout << "Original seating"<<endl;
    for (int i = 0; i < n; i++) cout << employees[i] << " ";
    cout << endl;
    insertionSort(employees, n);
    cout << "Sorted seating"<<endl;
    for (int i = 0; i < n; i++) cout << employees[i] << " ";
    cout << endl;
    return 0;
}


 
