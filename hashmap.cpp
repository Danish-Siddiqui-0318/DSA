#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node HT[10];

void init()
{
    for (int i = 0; i < 10; i++)
    {
        HT[i].data = -1;
        HT[i].next = NULL;
    }
}

void insert(int value)
{
    int ind = value % 10;
    if (HT[ind].data == -1)
    {
        HT[ind].data = value;
        HT[ind].next = NULL;
    }
    else
    {
        Node *temp = new Node;
        temp->data = value;
        temp->next = NULL;
        if (HT[ind].next == NULL)
        {
            HT[ind].next = temp;
        }
        else
        {
            Node *CurrentPtr = HT[ind].next;
            while (CurrentPtr->next != NULL)
            {
                CurrentPtr = CurrentPtr->next;
            }
            CurrentPtr->next = temp;
        }
        cout << "value is inserted";
    }
}

bool search(int value)
{
    Node *temp = new Node;
    int ind = value % 10;

    if (HT[ind].data == -1)
    {
        return false;
    }

    if (HT[ind].data == value)
    {
        return true;
    }

    Node *curr = HT[ind].next;

    while (curr != NULL)
    {
        if (curr->data == value)
        {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

int main()
{
    init();
    insert(10);
    cout << search(10);
    cout << endl;
    cout << search(650);

    return 0;
}