#include <iostream>
using namespace std;

class Hash
{
private:
    int *table;
    int size;
    
    int hashFunc(int key)
    {
        return key % size;
    }

public:
   Hash(int size = 10)
    {
        this->size = size;
        table = new int[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = -1;
        }
    }

    void insert(int key)
    {
        int index = hashFunc(key);

        while (table[index] != -1)
        { // linear probing
            index = (index + 1) % SIZE;
        }
        table[index] = key;
    }

    void remove(int key)
    {
        int index = hashFunc(key);

        for (int i = 0; i < size; i++)
        {
            int idx = (index + i) % SIZE;
            if (table[idx] == key)
            {
                table[idx] = -1;
                cout << "Key deleted\n";
                return;
            }
        }
        cout << "Key not found\n";
    }

    void search(int key)
    {
        int index = hashFunc(key);

        for (int i = 0; i < size; i++)
        {
            int idx = (index + i) % SIZE;
            if (table[idx] == key)
            {
                cout << "Key Found\n";
                return;
            }
        }
        cout << "Key Not Found\n";
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Index " << i << ": ";
            if (table[i] == -1)
                cout << "Empty";
            else
                cout << table[i];
            cout << endl;
        }
    }
};
int main() {
    Hash h;

    h.insert(15);
    h.insert(25);
    h.insert(35);

    h.search(25);
    h.remove(25);
    h.search(25);

    h.display();

    return 0;
}
