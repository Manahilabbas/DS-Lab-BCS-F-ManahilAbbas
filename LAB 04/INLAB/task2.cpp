#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key) {
   if(low <= high) {
      int mid = (low + high) / 2;
      if(arr[mid] == key) return mid;
      else if(arr[mid] < key) 
         return binarySearch(arr, mid+1, high, key);
      else 
         return binarySearch(arr, low, mid-1, key);
   }
   else return -1;
}

int main() {
   int n, roll = 1026;
   cout << "Enter num of employee IDs: ";
   cin >> n;

   int* arr = new int[n];
   cout << "Enter employee IDs in sorted order: ";
   for(int i=0; i<n; i++) {
      cin >> arr[i];}

   int last = roll % 100;
   int index = binarySearch(arr, 0, n-1, last);

   if(index != -1) {
      cout << "Employee with ID " << last 
           << " found at index " << index << endl; }
   else {
      int* newArr = new int[n+1];
      int pos = 0;
      while(pos<n && arr[pos]<last) {
         newArr[pos] = arr[pos];
         pos++;
      }

      newArr[pos] = last;
      for(int i=pos; i<n; i++) {
         newArr[i+1] = arr[i];
      }
      n++;

      cout << "ID not found. Inserted " << last 
           << " at index " << pos << endl;

      cout << "Updated IDs: ";
      for(int i=0; i<n; i++)
        { cout << newArr[i] << " ";}
      cout << endl;

      delete[] arr;
      arr = newArr; }

   return 0;
}
