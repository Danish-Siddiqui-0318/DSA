#include <iostream>
#include <cstdlib>
using namespace std;

// struct Node
// {
//     int data;
//     Node *next;
// };

// Node *SinglyLinkList = NULL;

// void Insert(int value)
// {
//     Node *temp = new Node;
//     temp->data = value;
//     temp->next = NULL;

//     if (SinglyLinkList == NULL)
//     {
//         SinglyLinkList = temp;
//     }
//     else
//     {
//         Node *currentPtr = SinglyLinkList;
//         while (currentPtr->next != NULL)
//         {
//             currentPtr = currentPtr->next;
//         }
//         currentPtr->next = temp;
//     }
// }

// void Delete(int value)
// {
//     if (SinglyLinkList == NULL)
//     {
//         cout << "List is empty";
//         return;
//     }

//     Node *temp = SinglyLinkList;
//     Node *prev = NULL;

//     if (temp->data == value)
//     {
//         SinglyLinkList = temp->next;
//         delete (temp);
//         cout << "Node Deleted";
//         return;
//     }

//     while (temp != NULL && temp->data != value)
//     {
//         prev = temp;
//         temp = temp->next;
//     }
//     if (temp == NULL)
//     {
//         cout << "Value Not Found";
//         return;
//     }

//     prev->next = temp->next;
//     delete (temp);
//     cout << "Value Deleted" << endl;
// }

// void Display()
// {
//     if (SinglyLinkList == NULL)
//     {
//         cout << "List is empty";
//         return;
//     }

//     Node *temp = SinglyLinkList;
//     while (temp != NULL)
//     {
//         cout << "Data" << temp->data << endl;
//         temp = temp->next;
//     }
// }

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            return;
        }
    }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << "Linklist is empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back()
    {
        if (head == NULL)
        {
            cout << "LinkList is empty" << endl;
            return;
        }

        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    // Insert(10);
    // Insert(50);
    // Insert(70);
    // Insert(90);
    // Display();

    // Delete(70);
    // Display();

    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(4);
    ll.print();
    ll.pop_front();
    ll.print();
    ll.pop_back();
    ll.print();
    return 0;
}