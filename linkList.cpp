#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *SinglyLinkedList = NULL;

void InsertAtEnd(int value)
{
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;

    if (SinglyLinkedList == NULL)
    {
        SinglyLinkedList = temp;
    }
    else
    {
        Node *CurrentPtr = SinglyLinkedList;
        while (CurrentPtr->next != NULL)
        {
            CurrentPtr = CurrentPtr->next;
        }
        CurrentPtr->next = temp;
    };
};

void DeleteNode(int value)
{
    if (SinglyLinkedList == NULL)
    {
        cout << "List is empty";
        return;
    }
    Node *temp = SinglyLinkedList;
    Node *prev = NULL;

    if (temp->data == value)
    {
        SinglyLinkedList = temp->next;
        free(temp);
        cout << "Node is deleted";
        return;
    }

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Value not found" << endl;
        return;
    }

    prev->next = temp->next;
    free(temp);
    cout << "Node Deleted" << endl;
}

void DisplayLinkList()
{
    if (SinglyLinkedList == NULL)
    {
        cout << "Empty LINKLIST" << std::endl;
    }
    else
    {
        Node *temp = SinglyLinkedList;
        while (temp != NULL)
        {
            cout << "Data" << temp->data << std::endl;
            temp = temp->next;
        };
    }
}





int main()
{
    DisplayLinkList(); // with single linked List
    InsertAtEnd(56);
    InsertAtEnd(46);
    InsertAtEnd(32);
    DisplayLinkList();
    DeleteNode(46);
    DisplayLinkList();

    // InsertAtEnd(44); // With Circular Linked List
    // InsertAtEnd(56);
    // InsertAtEnd(68);
    // InsertAtEnd(80);
    // Display();
    // Search(81);
    // Delete(56);
    // Display();

    // With Double Linked List
    // InsertAtEnd(56);
}