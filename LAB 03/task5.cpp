//  5. Convert Between Linked List Types
// Implement functions for conversion:
// 1. Convert a singly linked list into a doubly linked list.
// 2. Convert a singly linked list into a circular linked list.
// • Demonstrate both conversions with sample input lists.
#include <iostream>
using namespace std;

// Singly linked list node
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class Singly {
public:
    Node* head;
    Singly() { head = NULL; }

    void insertion(int val) {
        Node* newnode = new Node(val);
        if (!head) {
            head = newnode;
            return;
        }
        Node* temp = head;
        while (temp->next) { 
            temp = temp->next;
        }
        temp->next = newnode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void makeCircular(Node* head) {
    if (!head) return;
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = head; 
}


DNode* convertToDoubly(Node* head) {
    if (!head) return NULL;

    DNode* dhead = new DNode(head->data);//1st node
    DNode* prev = dhead;
    Node* scurr = head->next;

    while (scurr) {
        DNode* newNode = new DNode(scurr->data);
        prev->next = newNode;
        newNode->prev = prev;
        prev = newNode;
        scurr = scurr->next;
    }
    return dhead;
}

// Display doubly linked list forward and backward
void displayDoubly(DNode* head) {
    DNode* temp = head;
    DNode* tail= head;

    cout << "Forward: ";
    while (temp) {
        cout << temp->data << " ";
        tail=temp;
        temp = temp->next;
    }
    cout << endl;

    cout << "Backward: ";
    while (tail) {
        
        cout << tail->data << " ";
        tail = tail->prev;
        
    }
    cout << endl;
}

void displayCircular(Node* head, int count) {
    Node* temp = head;
    cout << "Circular: ";
    for (int i = 0; i < count; i++) {   
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Singly s1,s2;
    s1.insertion(1);
    s1.insertion(2);
    s1.insertion(3);
    s1.insertion(4);
    s2.insertion(1);
    s2.insertion(2);
    s2.insertion(3);
    s2.insertion(4);

    cout << "Singly List: ";
    s1.display();

    makeCircular(s1.head);
    displayCircular(s1.head, 8);  
    DNode* dhead = convertToDoubly(s2.head);
    displayDoubly(dhead);

    return 0;
}
