//  4. Josephus Problem using Circular Linked List
// Use a circular linked list to solve the Josephus problem:
// • N people stand in a circle, eliminating every k-th person until only one survives.
// • Input: N = 7, k = 3
// • Output: Position of survivor.
// • Hint: Use circular traversal and deletion.

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
class circularLinkedList{
    public:
    Node* head;
    circularLinkedList(){head=NULL;}
    void InsertAtLast(int n){
        Node* newnode= new Node(n);
        if(head==NULL){
           head=newnode;
           newnode->next=head;
           return;
        }
    Node* run=head;
    while(run->next!=head){
        run=run->next;
    }
run->next=newnode;
newnode->next=head;
}
   void Deletenode(Node* prev){
    Node* rest=prev->next;
    prev->next=rest->next;
    delete rest;
   
   }};
int josephus(int n, int k){
    circularLinkedList L1;
    for(int i=1;i<=n;i++){
        L1.InsertAtLast(i);
    }
    Node* run=L1.head;
    Node* prev;
    while(run->next!=run){
        for(int i=1;i<k;i++){
            prev = run;
            run = run->next;
         
        }
          cout << "Eliminated: " << run->data << endl;

        L1.Deletenode(prev);
        run = prev->next;  
    }
    return run->data;

}
int main(){
    int n,k;
    cout<<"enter numberof people"<<endl;
    cin>>n;
    cout<<"enter k"<<endl;
    cin>>k;
    cout<<"p="<<josephus(n,k);

    return 0;
}