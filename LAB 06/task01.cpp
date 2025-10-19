// Implement a stack using arrays. Support the following operations:
// 1. Push an element
// 2. Pop an element
// 3. Peek (top element)
// 4. Display stack contents
#include <iostream>
using namespace std;
class stack
{
public:
    int *arr;
    int capacity;
    int top;
    stack(int cap = 0)
    {
        capacity = cap;
        top = -1;
        arr = new int[capacity];
    }
     ~stack() 
    {
        delete[] arr;
        arr = nullptr;
    }
    void push(int n)
    {
        if (top == capacity - 1)
        {
            cout << "stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = n;
    }
    int pop()
    {
        if (top < 0)
        {
            cout << "stack underflow" << endl;
            return -1;
        }
        return arr[top--];
    }
    int peek()
    {
        if (top < 0)
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    stack s(10);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.display();
    cout << "poped: " << s.pop() << endl;
    cout << "peek element: " << s.peek();

    return 0;
}
