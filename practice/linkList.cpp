#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *SinglyLinkList = NULL;

void Insert(int value)
{
    Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;

    if (SinglyLinkList == NULL)
    {
        SinglyLinkList = temp;
    }
    else
    {
        Node *currentPtr = SinglyLinkList;
        while (currentPtr->next != NULL)
        {
            currentPtr = currentPtr->next;
        }
        currentPtr->next = temp;
    }
}

void Delete(int value)
{
    if (SinglyLinkList == NULL)
    {
        cout << "List is empty";
        return;
    }

    Node *temp = SinglyLinkList;
    Node *prev = NULL;

    if (temp->data == value)
    {
        SinglyLinkList = temp->next;
        delete (temp);
        cout << "Node Deleted";
        return;
    }

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Value Not Found";
        return;
    }

    prev->next = temp->next;
    delete (temp);
    cout << "Value Deleted" << endl;
}

void Display()
{
    if (SinglyLinkList == NULL)
    {
        cout << "List is empty";
        return;
    }

    Node *temp = SinglyLinkList;
    while (temp != NULL)
    {
        cout << "Data" << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    Insert(10);
    Insert(50);
    Insert(70);
    Insert(90);
    Display();

    Delete(70);
    Display();

    return 0;
}