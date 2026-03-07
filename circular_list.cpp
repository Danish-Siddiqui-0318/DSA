// Circular linked List
#include <iostream>
#include <cstdlib>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

Node *CircularLinkedList = NULL;
void InsertAtEnd(int value)
{
    Node *temp = new Node;
    temp = (Node *)malloc(sizeof(Node));
    temp->data = value;

    if (CircularLinkedList == NULL)
    {
        CircularLinkedList = temp;
        temp->next = CircularLinkedList;
    }
    else
    {
        Node *CurrentPtr = CircularLinkedList;
        while (CurrentPtr->next != CircularLinkedList)
        {
            CurrentPtr = CurrentPtr->next;
        }
        CurrentPtr->next = temp;
        temp->next = CircularLinkedList;
    };
};

void Display()
{
    if (CircularLinkedList == NULL)
    {
        cout << "Circular list is empty" << endl;
        return;
    }

    Node *temp = CircularLinkedList;
    do
    {
        cout << "Data " << temp->data << endl;
        temp = temp->next;
    } while (temp != CircularLinkedList);
}
void Search(int value)
{
    if (CircularLinkedList == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = CircularLinkedList;
    do
    {
        if (temp->data == value)
        {
            cout << "Value founded" << endl;
            return;
        }
        temp = temp->next;
    } while (temp != CircularLinkedList);

    cout << "Value not found" << endl;
}

void Delete(int value)
{
    if (CircularLinkedList == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *current = CircularLinkedList;
    Node *prev = NULL;

    if (current->next == CircularLinkedList && current->data == value)
    {
        delete current;
        CircularLinkedList = NULL;
        cout << "Node Deleted" << endl;
        return;
    }

    if (current->data == value)
    {
        Node *last = CircularLinkedList;

        while (last->next != CircularLinkedList)
        {
            last = last->next;
        }

        CircularLinkedList = current->next;
        last->next = CircularLinkedList;
        delete current;
        cout << "Node deleted" << endl;
        return;
    }

    prev = current;
    current = current->next;
    while (current != CircularLinkedList)
    {
        if (current->data == value)
        {
            prev->next = current->next;
            delete current;
            cout << "Node Deleted" << endl;
            return;
        }
        prev = current;
        current = current->next;
    }

    cout << "Value not Found" << endl;
}

int main()
{
    // DisplayLinkList(); // with single linked List
    // InsertAtEnd(56);
    // InsertAtEnd(46);
    // InsertAtEnd(32);
    // DisplayLinkList();
    // DeleteNode(46);
    // DisplayLinkList();

    InsertAtEnd(44); // With Circular Linked List
    InsertAtEnd(56);
    InsertAtEnd(68);
    InsertAtEnd(80);
    Display();
    Search(81);
    Delete(56);
    Display();

    // With Double Linked List
    // InsertAtEnd(56);
}