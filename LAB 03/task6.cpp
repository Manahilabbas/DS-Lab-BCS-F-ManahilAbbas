//  6. Flatten a Multilevel Linked List
// Each node has:
// • next pointer (normal linked list connection).
// • child pointer (points to another linked list).
// Write a function to flatten the structure so that all nodes appear in a single-level list.
// • Example:
// • 1 → 2 → 3
// •     |
//       4 → 5
// Output: 1 → 2 → 4 → 5 → 3

#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* child;
Node(int val){
    data=val;
    next=NULL;
    child=NULL;
}
};
class LinkedList{
    public:
    Node* head;
    LinkedList(){head=NULL;}
    void insertchild(int parentVal, Node* childhead) {
        Node* temp = head;
        while (temp && temp->data != parentVal) {
            temp = temp->next;
        }
        if (temp) {
            temp->child = childhead;
        }
    }

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

};
void flattn(Node* head){
    if(!head){return;}
Node* temp=head;
Node* child=NULL;
while(temp){
    cout<<temp->data<<" ";
    if(temp->child!=NULL){
     child =temp->child;
     while (child)
     {
        cout<<child->data<<" ";
        child=child->next;
     }
    }
    temp=temp->next;
}
}
int main(){
    LinkedList parent,child;
    parent.insertion(1);
    parent.insertion(2);
    parent.insertion(3);
    child.insertion(4);
    child.insertion(5);
    parent.insertchild(2,child.head);
    flattn(parent.head);

    return 0;
}