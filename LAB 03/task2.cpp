//  2. Merge Two Sorted Singly Linked Lists
// Implement a function to merge two sorted singly linked lists into one sorted list.

// • Example:
// o List A: 1 → 3 → 5
// o List B: 2 → 4 → 6
// o Output: 1 → 2 → 3 → 4 → 5 → 6
// • Bonus: Solve without creating new nodes (rearrange pointers).

#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
Node(int val){
    data=val;
    next=NULL;
}
};
class LinkedList{    public:
    Node* head;
    LinkedList(){head=NULL;}
    LinkedList(Node* ptr){head=ptr;}
    
    void Insertion(int val){
        Node* n=new Node(val);
        if(head==NULL){
            head=n;
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
    }
    
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};


Node* mergeList(Node* head1, Node*head2){
      Node*ptr1=head1;
       Node*ptr2=head2;
     Node* dummyhead=new Node(-11);
     Node* ptr3=dummyhead;
while(ptr1!=NULL&&ptr2!=NULL)
     {
        if(ptr1->data>ptr2->data){
            ptr3->next=ptr2;
           ptr2=ptr2->next;}
           else{
            ptr3->next=ptr1;
            ptr1=ptr1->next;
           }
           ptr3=ptr3->next;
     }
     if(ptr1){
        ptr3->next=ptr1;
     }
     if(ptr2){
        ptr3->next=ptr2;
     }
     return dummyhead->next;

}
int main(){
    LinkedList l1,l2;
    l1.Insertion(1);
    l1.Insertion(4);
    l1.Insertion(5);
    cout<<"List 1: ";
    l1.display();
    cout<<endl;
    l2.Insertion(2);
    l2.Insertion(3);
    l2.Insertion(10);
    cout<<"List 2: ";
    l2.display();
    cout<<endl;
    Node* head=mergeList(l1.head,l2.head);
    LinkedList l3(head);
    cout<<"Merge List :";
   l3.display();
    return 0;
}