

#include <iostream>
using namespace std;

bool isMaxHeap(int arr[], int size) {
    for (int i = 0; i <= (size - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && arr[i] < arr[left])
            return false;

        if (right < size && arr[i] < arr[right])
            return false;
    }
    return true;
}

void heapifyDown(int arr[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyDown(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    for (int i = (size / 2) - 1; i >= 0; i--)
        heapifyDown(arr, size, i);

    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapifyDown(arr, i, 0);
    }
}

int main() {
    int arr[] = {8, 7, 6, 5, 4};
    int size = 5;

    if (isMaxHeap(arr, size))
        cout << " it is a Max Heap.\n";
    else
        cout << "it is not a Max Heap.\n";

    heapSort(arr, size);

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}
