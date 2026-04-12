#include <iostream>
using namespace std;

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

class CircularLinkList
{
    Node *head;
    Node *tail;

public:
    CircularLinkList()
    {
        head = tail = NULL;
    }

    void pushback(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
            return;
        }
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }

    void pushfront(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
            return;
        }
        newNode->next = head;
        newNode = head;
        tail->next = head;
    }

    void popback()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }

        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = head;
        delete tail;
        tail = temp;
    }

    void popfront()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }

        Node *temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }

    void deleteNo(int val)
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }
        Node *temp = head;
        Node *prev = NULL;
        if (head->data == val)
        {
            popfront();
            return;
        }
        temp = head->next;

        while (temp != head)
        {
            if (temp->data == val)
            {
                prev->next = temp->next;
                if (temp == tail)
                {
                    tail = prev;
                }

                delete temp;
                cout << "Node Deleted\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Value not found\n";
    }
     void print()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node *temp = head;

        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "(head)" << endl;
    }
};

int main()
{
    CircularLinkList cl;
    cl.pushback(1);
    cl.pushback(2);
    cl.pushback(3);
    cl.pushback(4);

    cl.print();

    cl.deleteNo(3);
    cl.print();

    cl.popfront();
    cl.print();

    cl.popback();
    cl.print();
    return 0;
}