#include <iostream>
#include <string>
using namespace std;

class StudentHashTable
{
private:
    struct Student
    {
        int roll;
        string name;
    };

    Student *table;
    int size;

    int hashFunc(int key)
    {
        return key % size;
    }

public:
    StudentHashTable(int sz = 15)
    {
        size = sz;
        table = new Student[size];
        for (int i = 0; i < size; i++)
        {
            table[i].roll = -1;
            table[i].name = "";
        }
    }

    void InsertRecord(int roll, string name)
    {
        int index = hashFunc(roll);
        for (int attempt = 0; attempt < size; attempt++)
        {
            int idx = (index + attempt * attempt) % size;
            if (table[idx].roll == -1)
            {
                table[idx].roll = roll;
                table[idx].name = name;
                cout << "Inserted at index " << idx << endl;
                return;
            }
        }
        cout << "Hash table full! Cannot insert.\n";
    }

    void SearchRecord(int roll)
    {
        int index = hashFunc(roll);
        for (int attempt = 0; attempt < size; attempt++)
        {
            int idx = (index + attempt * attempt) % size;
            if (table[idx].roll == roll)
            {
                cout << "Record Found: " << table[idx].name << endl;
                return;
            }
        }
        cout << "Record not found\n";
    }

    void Display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Index " << i << ": ";
            if (table[i].roll == -1)
                cout << "Empty\n";
            else
                cout << table[i].roll << " - " << table[i].name << endl;
        }
    }
};

int main()
{
    StudentHashTable sht;

    sht.InsertRecord(101, "Alice");
    sht.InsertRecord(102, "Bob");
    sht.InsertRecord(116, "Charlie");
    sht.Display();

    sht.SearchRecord(102);
    sht.SearchRecord(200);

    return 0;
}
