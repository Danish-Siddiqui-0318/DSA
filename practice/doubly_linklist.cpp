// #include <iostream>
// #include <cstdlib>
// using namespace std;

// struct Node
// {
//     int data;
//     Node *next;
//     Node *prev;
// };

// Node *DoublyLinkList = NULL;

// void insert(int value)
// {
//     Node *temp = new Node;
//     temp->data = value;
//     temp->next = NULL;
//     temp->prev = NULL;
//     if (DoublyLinkList == NULL)
//     {
//         DoublyLinkList = temp;
//         cout << "Value is Inserted" << endl;
//         return;
//     }
//     else
//     {
//         Node *CurrentPtr = DoublyLinkList;
//         while (CurrentPtr->next != NULL)
//         {
//             CurrentPtr = CurrentPtr->next;
//         }
//         CurrentPtr->next = temp;
//         temp->prev = CurrentPtr;
//     }
// }

// void search(int value)
// {
//     if (DoublyLinkList == NULL)
//     {
//         cout << "List is empty" << endl;
//         return;
//     }
//     Node *temp = DoublyLinkList;
//     while (temp != NULL)
//     {
//         if (temp->data == value)
//         {
//             cout << "Value found : " << temp->data << endl;
//             return;
//         }
//         temp = temp->next;
//     }

//     cout << "Value not found" << endl;
// }

// void Delete(int value)
// {
//     if (DoublyLinkList == NULL)
//     {
//         cout << "List is empty" << endl;
//         return;
//     }
//     Node *temp = DoublyLinkList;
//     if (temp->data == value)
//     {
//         DoublyLinkList = temp->next;
//         if (DoublyLinkList != NULL)
//         {
//             DoublyLinkList->prev = NULL;
//         }
//         delete (temp);
//         cout << "Value deleted" << endl;
//         return;
//     }
//     while (temp != NULL && temp->data != value)
//     {
//         temp = temp->next;
//     }

//     if (temp == NULL)
//     {
//         cout << "Value not found" << endl;
//         return;
//     }

//     temp->prev->next = temp->next;
//     if (temp->next != NULL)
//     {
//         temp->next->prev = temp->prev;
//     }
//     delete (temp);
//     cout << "Value deleted" << endl;
// }

// void display()
// {
//     if (DoublyLinkList == NULL)
//     {
//         cout << "List is empty" << endl;
//         return;
//     }
//     Node *temp = DoublyLinkList;
//     while (temp != NULL)
//     {
//         cout << "Value : " << temp->data << endl;
//         temp = temp->next;
//     }
// }

// int main()
// {

//     // With Double Linked List
//     insert(56);
//     insert(45);
//     insert(34);
//     insert(85);
//     search(56);
//     search(78);
//     display();
//     Delete(56);
//     search(56);
//     display();
// }

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList
{
    Node *head;
    Node *tail;

public:
    DoublyList()
    {
        head = tail = NULL;
    }
    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void pushBack(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void popfront()
    {
        if (head == NULL)
        {
            cout << "Linklist is empty" << endl;
            return;
        }

        Node *temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        temp->next = NULL;
        delete temp;
    }

    void popback()
    {
        if (head == NULL)
        {
            cout << "Linklist is empty" << endl;
            return;
        }
        Node *temp = tail;
        tail = tail->prev;
        if (tail != NULL)
        {
            tail->next = NULL;
        }
        temp->prev = NULL;
        delete temp;
    }

    void printDoubly()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{

    DoublyList dll;
    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);
    dll.printDoubly();
    dll.pushBack(4);
    dll.pushBack(5);
    dll.printDoubly();
    dll.popfront();
    dll.printDoubly();
    dll.popback();
    dll.printDoubly();

    return 0;
}