// Doubly  Linked List

#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *DoublyLinkedList = NULL;

void InsertAtEnd(int value)
{
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;

    if (DoublyLinkedList == NULL)
    {
        DoublyLinkedList = temp;
        cout << "Value is inserted \n";
        return;
    }
    else
    {
        Node *CurrentPtr = DoublyLinkedList;
        while (CurrentPtr->next != NULL)
        {
            CurrentPtr = CurrentPtr->next;
        }
        CurrentPtr->next = temp;
        temp->prev = CurrentPtr;
    };
    // cout << "Value is inserted";
};

void Display()
{
    if (DoublyLinkedList == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }
    Node *temp = DoublyLinkedList;
    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void Search(int key)
{
    if (DoublyLinkedList == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = DoublyLinkedList;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            cout << "Value is found " << key << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Value Not Found" << endl;
}
void Delete(int key)
{
    if (DoublyLinkedList == NULL)
    {
        cout << "List is empty";
        return;
    }
    Node *temp = DoublyLinkedList;
    if (temp->data == key)
    {
        DoublyLinkedList = temp->next;
        if (DoublyLinkedList != NULL)
        {
            DoublyLinkedList->prev = NULL;
            free(temp);
            cout << "Value is Deleted" << endl;
            return;
        }
    }

    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }
    while (temp == NULL)
    {
        cout << "Value Not found" << endl;
        return;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    free(temp);
    cout << "Value is Deleted";
}

int main()
{

    // With Double Linked List
    InsertAtEnd(56);
    InsertAtEnd(45);
    InsertAtEnd(34);
    InsertAtEnd(85);
    Search(56);
    Search(78);
    Display();
    Delete(56);
    Search(56);
    Display();
}