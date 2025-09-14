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

    void Insertion(int val) {
        Node* n = new Node(val);
        if (head == nullptr) {
            head = n;
            return;}
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = n;
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
bool isPalindrome(LinkedList& L) {
    if (!L.head || !L.head->next) return true;

    Node* slow = L.head;
    Node* fast = L.head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* secondHalf = reverseList(slow);
    Node* p1 = L.head;
    Node* p2 = secondHalf;
    bool palindrome = true;
    while (p2) { 
        if (p1->data != p2->data) {
            palindrome = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    slow = reverseList(secondHalf);
    return palindrome;
}

int main() {
    LinkedList L1;
    int n, val;
    cout << "How many numbers you want to insert: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Insert number: ";
        cin >> val;
        L1.Insertion(val);
    }

    if (isPalindrome(L1))
        cout << "It is a palindrome" << endl;
    else
        cout << "It is NOT a palindrome" << endl;

    return 0;
}
