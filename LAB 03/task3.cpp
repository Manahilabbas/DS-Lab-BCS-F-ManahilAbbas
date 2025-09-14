//  3. Reverse in Groups of K
// Reverse nodes of a singly linked list in groups of size k.
// • Example:
// o Input: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8, with k = 3
// o Output: 3 → 2 → 1 → 6 → 5 → 4 → 8 → 7
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() { head = nullptr; }
    
    LinkedList(Node* ptr){head=ptr;}

    void Insertion(int val) {
        Node* n = new Node(val);
        if (head == nullptr) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = n;
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
Node* reverK(Node* head,int k){
     if (!head) return nullptr;

    Node* curr = head;
    Node* prevTail = nullptr;
    Node* newHead = nullptr;
 while (curr) {
        Node* ptr1 = curr;
        Node* ptr2 = curr;
for(int i=0;i<k-1;i++){
    ptr2=ptr2->next;
}
if (!ptr2) break;

        Node* nextGroup = ptr2->next;
        ptr2->next = nullptr;// break linkedlist to reverse

Node* revHead = reverseList(ptr1); // create new head to attached with our list
        Node* revTail = ptr1;              

        if (!newHead) {
            newHead = revHead;
        } else {
            prevTail->next = revHead;
        }

        prevTail = revTail;
        curr = nextGroup;
    }
    if (prevTail) prevTail->next = curr;

    return newHead ? newHead : head;
}
int main(){
    LinkedList l1;
    l1.Insertion(1);
    l1.Insertion(2);
    l1.Insertion(3);
    l1.Insertion(4);
    l1.Insertion(5);
    l1.Insertion(6);
    l1.Insertion(7);
    l1.Insertion(8);
    l1.Insertion(9);
    l1.display();
    cout<<endl;
    LinkedList l2(reverK(l1.head,3));
    cout<<"Afterreverse k elements"<<endl;
    l2.display();
    return 0;
}