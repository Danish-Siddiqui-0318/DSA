#include <iostream>
#include <cstdlib>
using namespace std;

const int SIZE = 7;
int hashtable[SIZE];

void init()
{
    for (int i = 0; i < SIZE; i++)
    {
        hashtable[i] = -1;
    }
}
int hashfunction(int key)
{
    return key % SIZE;
}
// for linear
void insert(int key)
{
    int index = hashfunction(key);
    int i = 0;
    while (hashtable[(index + 1) % SIZE] != -1)
    {
        i++;
    }

    hashtable[(index + i) % SIZE] = key;
}

// for quadratic

void insertQuadratic(int key)
{
    int index = hashfunction(key);
    int i = 0;
    while (hashtable[(index + i * i) % SIZE] != NULL)
    {
        i++;
    }
    hashtable[(index + i * i) % SIZE] = key;
}

void display()
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << i << " : " << hashtable[i] << endl;
    }
}

int main()
{
    init();
    insert(20);
    insert(30);
    insert(50);
    insert(70);
    display();

    return 0;
}