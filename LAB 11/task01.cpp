#include <iostream>
using namespace std;

struct Node
{
    string key;
    string value;
    Node *next;
};

class HashTable
{
    Node *table[10];

    int hashFunc(string key)
    {
        int sum = 0;
        for (int i = 0; i < key.length(); i++)
            sum += key[i];
        return sum % 10;
    }

public:
    HashTable()
    {
        for (int i = 0; i < 10; i++)
            table[i] = NULL;
    }

    void insert(string key, string value)
    {
        int index = hashFunc(key);

        Node *newNode = new Node;
        newNode->key = key;
        newNode->value = value;
        newNode->next = table[index];

        table[index] = newNode;
    }

    void display()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << "Index " << i << ": ";
            Node *temp = table[i];

            while (temp != NULL)
            {
                cout << "(" << temp->key << ", "
                     << temp->value << ") ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    HashTable myhash;

    myhash.insert("A", "aaaaa");
    myhash.insert("B", "bbbbb");
    myhash.insert("C", "ccccc");
    myhash.insert("A", "zzzzz");

    myhash.display();
}
