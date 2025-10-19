// Implement a stack using linked lists. Demonstrate its use with a real-life example (e.g., browser
// history navigation).
#include <iostream>
using namespace std;
class node
{
public:
    string data;
    node *next;
    node(string x)
    {
        data = x;
        next = NULL;
    }
};
class stack
{
public:
    node *top;
    int count;
    stack()
    {
        top = NULL;
        count = 0;
    }
    void push(string n)
    {
        node *temp = top;
        node *newval = new node(n);
        top = newval;
        top->next = temp;
        count++;
    }
    string pop()
    {
        if (top == NULL)
        {
            return "stack underflow";
        }
        node *temp = top;
        top = top->next;
        string data = temp->data;
        delete temp;
        count--;
        return data;
    }
    string peek()
    {
        if (top == NULL)
        {
            return "stack underflow";
        }
        return top->data;
    }
    void display()
    {
        if (top == NULL)
        {
            cout << "stack is empty\n";
            return;
        }
        node *temp = top;
        for (int i = 0; i <= count; i++)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};
int main()
{
    stack browserHistory;

    cout << "Opening pages...\n";
    browserHistory.push("www.google.com");
    browserHistory.push("www.youtube.com");
    browserHistory.push("www.github.com");

    cout << "\nCurrent page: " << browserHistory.peek() << endl;

    cout << "\nGoing back...\n";
    cout << "Popped: " << browserHistory.pop() << endl;
    cout << "Now on: " << browserHistory.peek() << endl;

    cout << "\nGoing back again...\n";
    cout << "Popped: " << browserHistory.pop() << endl;
    cout << "Now on: " << browserHistory.peek() << endl;

    cout << "\nBrowser history (most recent first):\n";
    browserHistory.display();

    return 0;
}
