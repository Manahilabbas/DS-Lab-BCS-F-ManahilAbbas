#include <iostream>
using namespace std;

class PairSumHash
{
private:
    struct Entry
    {
        int sum;
        int a, b;
    };

    Entry *table;
    int size;

    int hashFunc(int key)
    {
        return key % size;
    }

public:
    PairSumHash(int sz)
    {
        size = sz;
        table = new Entry[size];
        for (int i = 0; i < size; i++)
        {
            table[i].sum = -1;
        }
    }

    bool insert(int sum, int a, int b)
    {
        int index = hashFunc(sum);
        for (int i = 0; i < size; i++)
        {
            int idx = (index + i) % size;
            if (table[idx].sum == -1)
            {
                table[idx].sum = sum;
                table[idx].a = a;
                table[idx].b = b;
                return true;
            }
            else if (table[idx].sum == sum)
            {
                cout << "(" << table[idx].a << ", " << table[idx].b << ") and (" << a << ", " << b << ")\n";
                return false;
            }
        }
        return true;
    }
};

int main()
{
    int arr[] = {3, 4, 7, 1, 2, 9, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    PairSumHash hash(50);

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (!hash.insert(arr[i] + arr[j], arr[i], arr[j]))
            {
                found = true;
                break;
            }
        }
        if (found)
            break;
    }

    if (!found)
        cout << "No pairs found\n";

    return 0;
}
