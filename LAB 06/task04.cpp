// Implement a circular queue using arrays. Handle the following conditions correctly:
// 1. Enqueue when rear wraps around
// 2. Dequeue when front moves ahead
// 3. Prevent overflow when queue is full
#include <iostream>
using namespace std;

#define SIZE 5 // maximum size of the circular queue

class CircularQueue
{
private:
    int items[SIZE];
    int front, rear;

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
            return true;
        return false;
    }

    bool isEmpty()
    {
        return (front == -1);
    }
    void enqueue(int element)
    {
        if (isFull())
        {
            cout << "Queue is FULL!" << endl;
            return;
        }

        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        cout << "Inserted: " << element << endl;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is EMPTY!" << endl;
            return;
        }

        cout << "Deleted: " << items[front] << endl;

        if (front == rear)
        {
            // Queue has only one element
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is EMPTY!" << endl;
            return;
        }

        cout << "Queue elements are: ";
        int i = front;
        while (true)
        {
            cout << items[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main()
{
    CircularQueue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    return 0;
}
