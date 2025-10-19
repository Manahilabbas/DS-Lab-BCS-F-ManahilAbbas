// Implement a linear queue using arrays with the following operations:
// 1. Enqueue
// 2. Dequeue
// 3. Display queue contents
// 4. Check if queue is empty/full
#include <iostream>
using namespace std;
class queue
{
public:
    int *arr;
    int capacity;
    int size;
    queue(int cap = 0)
    {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }
    void enqueue(int n)
    {
        if (isfull())
        {
            cout << "stack overflow" << endl;
            return;
        }

        arr[size] = n;
        size++;
    }
    int dequeue()
    {
        if (isempty())
        {
            cout << "queue is empty" << endl;
            return -1;
        }
        int data = arr[0];
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
        return data;
    }

    void display()
    {
        if (isempty())
        {
            cout << "queue is empty" << endl;
            return;
        }
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    bool isempty() { return size == 0; }
    bool isfull() { return size == capacity; }
};
int main()
{
    queue s(10);
    s.enqueue(1);
    s.enqueue(2);
    s.enqueue(3);
    s.enqueue(4);
    s.enqueue(5);
    s.display();
    cout << "poped: " << s.dequeue() << endl;

    return 0;
}
