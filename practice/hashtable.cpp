#include <iostream>
using namespace std;

class HashTable
{
    int table[10];
    int size;

public:
    HashTable()
    {
        size = 10;
        for (int i = 0; i < size; i++)
        {
            table[i] = -1;
        }
    }
    void print()
    {
        cout << "Index\tValue" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << i << "\t";
            if (table[i] == -1)
            {
                cout << "EMPTY" << endl;
            }
            else
            {
                cout << table[i];
            }
            cout << endl;
        }
    }

    void insert(int key)
    {
        int hash = key % size;
        // first check original index
        if (table[hash] == -1)
        {
            table[hash] = key;
            return;
        }

        // Collision occurred/ for probing
        for (int i = 0; i < size; i++)
        {
            // int index = (hash + i) % size; // linear probing
            int index = (hash + i ^ 2) % size;
            if (table[index] == -1)
            {
                table[index] = key;
                return;
            }
        }
        cout << "Hash Table Full";
    }
};