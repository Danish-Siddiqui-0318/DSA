#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *DoublyLinkList = NULL;

void insert(int value)
{
    Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;
    if (DoublyLinkList == NULL)
    {
        DoublyLinkList = temp;
        cout << "Value is Inserted" << endl;
        return;
    }
    else
    {
        Node *CurrentPtr = DoublyLinkList;
        while (CurrentPtr->next != NULL)
        {
            CurrentPtr = CurrentPtr->next;
        }
        CurrentPtr->next = temp;
        temp->prev = CurrentPtr;
    }
}

void search(int value)
{
    if (DoublyLinkList == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = DoublyLinkList;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            cout << "Value found : " << temp->data << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Value not found" << endl;
}

void Delete(int value)
{
    if (DoublyLinkList == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = DoublyLinkList;
    if (temp->data == value)
    {
        DoublyLinkList = temp->next;
        if (DoublyLinkList != NULL)
        {
            DoublyLinkList->prev = NULL;
        }
        delete (temp);
        cout << "Value deleted" << endl;
        return;
    }
    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Value not found" << endl;
        return;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    delete (temp);
    cout << "Value deleted" << endl;
}

void display()
{
    if (DoublyLinkList == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = DoublyLinkList;
    while (temp != NULL)
    {
        cout << "Value : " << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{

    // With Double Linked List
    insert(56);
    insert(45);
    insert(34);
    insert(85);
    search(56);
    search(78);
    display();
    Delete(56);
    search(56);
    display();
}