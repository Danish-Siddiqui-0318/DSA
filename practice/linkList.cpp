#include <iostream>
#include <cstdlib>
using namespace std;

// // struct Node
// // {
// //     int data;
// //     Node *next;
// // };

// // Node *SinglyLinkList = NULL;

// // void Insert(int value)
// // {
// //     Node *temp = new Node;
// //     temp->data = value;
// //     temp->next = NULL;

// //     if (SinglyLinkList == NULL)
// //     {
// //         SinglyLinkList = temp;
// //     }
// //     else
// //     {
// //         Node *currentPtr = SinglyLinkList;
// //         while (currentPtr->next != NULL)
// //         {
// //             currentPtr = currentPtr->next;
// //         }
// //         currentPtr->next = temp;
// //     }
// // }

// // void Delete(int value)
// // {
// //     if (SinglyLinkList == NULL)
// //     {
// //         cout << "List is empty";
// //         return;
// //     }

// //     Node *temp = SinglyLinkList;
// //     Node *prev = NULL;

// //     if (temp->data == value)
// //     {
// //         SinglyLinkList = temp->next;
// //         delete (temp);
// //         cout << "Node Deleted";
// //         return;
// //     }

// //     while (temp != NULL && temp->data != value)
// //     {
// //         prev = temp;
// //         temp = temp->next;
// //     }
// //     if (temp == NULL)
// //     {
// //         cout << "Value Not Found";
// //         return;
// //     }

// //     prev->next = temp->next;
// //     delete (temp);
// //     cout << "Value Deleted" << endl;
// // }

// // void Display()
// // {
// //     if (SinglyLinkList == NULL)
// //     {
// //         cout << "List is empty";
// //         return;
// //     }

// //     Node *temp = SinglyLinkList;
// //     while (temp != NULL)
// //     {
// //         cout << "Data" << temp->data << endl;
// //         temp = temp->next;
// //     }
// // }

// class Node
// {
// public:
//     int data;
//     Node *next;

//     Node(int val)
//     {
//         data = val;
//         next = NULL;
//     }
// };

// class List
// {
//     Node *head;
//     Node *tail;

// public:
//     List()
//     {
//         head = tail = NULL;
//     }

//     // void push_front(int val)
//     // {
//     //     Node *newNode = new Node(val);
//     //     if (head == NULL)
//     //     {
//     //         head = tail = newNode;
//     //         return;
//     //     }
//     //     else
//     //     {
//     //         newNode->next = head;
//     //         head = newNode;
//     //     }
//     // }

//     void pushfront(int val)
//     {
//         Node *newNode = new Node(val);
//         if (head == NULL)
//         {
//             head = tail = newNode;
//             return;
//         }
//         else
//         {
//             newNode->next = head;
//             head = newNode;
//         }
//     }

//     // void push_back(int val)
//     // {
//     //     Node *newNode = new Node(val);
//     //     if (head == NULL)
//     //     {
//     //         head = tail = newNode;
//     //         return;
//     //     }
//     //     else
//     //     {
//     //         tail->next = newNode;
//     //         tail = newNode;
//     //         return;
//     //     }
//     // }

//     void pushback(int val)
//     {
//         Node *newNode = new Node(val);
//         if (head == NULL)
//         {
//             head = tail = newNode;
//             return;
//         }
//         else
//         {
//             tail->next = newNode;
//             newNode = tail;
//             return;
//         }
//     }

//     // void pop_front()
//     // {
//     //     if (head == NULL)
//     //     {
//     //         cout << "Linklist is empty" << endl;
//     //         return;
//     //     }
//     //     Node *temp = head;
//     //     head = head->next;
//     //     temp->next = NULL;
//     //     delete temp;
//     // }

//     void popfront()
//     {
//         if (head == NULL)
//         {
//             cout << "Linklist is empty" << endl;
//             return;
//         }

//         Node *temp = head;
//         head = head->next;
//         temp->next = NULL;
//         delete temp;
//     }

//     // void pop_back()
//     // {
//     //     if (head == NULL)
//     //     {
//     //         cout << "LinkList is empty" << endl;
//     //         return;
//     //     }

//     //     Node *temp = head;
//     //     while (temp->next != tail)
//     //     {
//     //         temp = temp->next;
//     //     }
//     //     temp->next = NULL;
//     //     delete tail;
//     //     tail = temp;
//     // }

//     void popback()
//     {
//         if (head == NULL)
//         {
//             cout << "LinkList is empty" << endl;
//             return;
//         }

//         Node *temp = head;
//         while (temp->next != tail)
//         {
//             temp = temp->next;
//         }

//         temp->next = NULL;
//         delete tail;
//         tail = temp;
//     }

//     void deleteNo(int val)
//     {
//         Node *temp = head;
//         if (head == NULL)
//         {
//             cout << "LinkList is empty" << endl;
//             return;
//         }

//         if (head->data == val)
//         {
//             head = head->next;
//             temp->next = NULL;
//             delete temp;
//             return;
//         }

//         Node *prev = NULL;
//         while (temp->next != NULL && temp->data != val)
//         {
//             prev = temp;
//             temp = temp->next;
//         }

//         if (temp == NULL)
//         {
//             cout << "Value not found" << endl;
//             return;
//         }

//         prev->next = temp->next;
//         delete temp;
//         cout << "Node Deleted" << endl;
//     }

//     void deleteNo(int val)
//     {
//         Node *temp = head;
//         if (head == NULL)
//         {
//             cout << "LinkList is empty" << endl;
//             return;
//         }
//         if (head->data == val)
//         {
//             head = head->next;
//             temp->next = NULL;
//             delete temp;
//             return;
//         }

//         Node *prev = NULL;
//         while (temp->next != NULL && temp->data != val)
//         {
//             prev = temp;
//             temp = temp->next;
//         }
//         if (temp == NULL)
//         {
//             cout << "Value not found" << endl;
//             return;
//         }
//         prev->next = temp->next;
//         delete temp;
//         cout << "Node Deleted" << endl;
//     }

//     // void reverseList()
//     // {
//     //     Node *prev = NULL;
//     //     Node *curr = head;
//     //     Node *next = NULL;
//     //     Node *oldhead = head;
//     //     while (curr != NULL)
//     //     {
//     //         next = curr->next;
//     //         curr->next = prev;
//     //         prev = curr;
//     //         curr = next;
//     //     }
//     //     tail = oldhead;
//     //     head = prev;
//     // }

//     void reverseList()
//     {
//         Node *prev = NULL;
//         Node *curr = head;
//         Node *next = NULL;
//         Node *oldHead = head;
//         while (curr !-NULL)
//         {
//             next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr->next;
//         }
//         head = prev;
//         tail = oldHead;
//     }

//     Node *middleList()
//     {
//         if (head == NULL)
//         {
//             return NULL;
//         }
//         Node *slow = head;
//         Node *fast = head;
//         while (fast != NULL && fast->next != NULL)
//         {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         return slow;
//     }

//     void print()
//     {
//         Node *temp = head;
//         while (temp != NULL)
//         {
//             cout << temp->data << " -> ";
//             temp = temp->next;
//         }
//         cout << "NULL" << endl;
//     }
// };

// int main()
// {
//     // Insert(10);
//     // Insert(50);
//     // Insert(70);
//     // Insert(90);
//     // Display();

//     // Delete(70);
//     // Display();

//     List ll;

//     ll.push_back(1);
//     ll.push_back(2);
//     ll.push_back(3);
//     ll.push_back(4);
//     ll.push_back(5);
//     // ll.print();
//     // ll.deleteNo(4);

//     cout << "Before Reverse:\n";
//     ll.print();

//     ll.reverseList(); // 🔥 call function

//     cout << "After Reverse:\n";
//     ll.print();
//     Node *middle = ll.middleList();
//     cout << " Middle of this linkList " << middle->data << endl;
//     return 0;
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
        }
    }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << "Linklist is empty";
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
            cout << "LL is empty" << endl;
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

    void insert(int val, int pos)
    {
        if (pos < 0)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        if (pos == 0)
        {
            push_front(val);
            return;
        }

        Node *newNode = new Node(val);
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Invalid Position" << endl;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    int Search(int val)
    {
        Node *temp = head;
        int idx = 0;
        while (temp != NULL)
        {
            if (temp->data == val)
            {
                return idx;
            }
            temp = temp->next;
            idx++;
        }

        return -1;
    }

    void printLL()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverseList()
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;

        head = tail;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }

    void deleteFromLast(int pos)
    {

        if (head == NULL)
        {
            cout << "List is Empty" << endl;
            return;
        }
        int lenght = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            lenght++;
        }

        if (pos > lenght || pos <= 0)
        {
            cout << "Invalid Postion" << endl;
            return;
        }

        int posToDelete = lenght - pos;

        if (posToDelete == 0)
        {
            temp = head;
            head = head->next;
            delete temp;
            return;
        }

        temp = head;
        Node *prev = NULL;

        for (int i = 0; i < posToDelete; i++)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        delete temp;

        cout << "Node Deleted" << endl;
    }

    void DeleteNo(int val)
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "Linklist is empty" << endl;
        }
        if (head->data == val)
        {
            head = head->next;
            temp->next = NULL;
            delete temp;
            return;
        }

        Node *prev = NULL;
        while (temp->next != NULL && temp->data != val)
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
        delete temp;
        cout << "Node is Deleled" << endl;
    }

    Node *MiddleLL()
    {
        Node *slow = head;
        Node *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main()
{
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(7);
    ll.insert(6, 3);
    ll.printLL();
    // ll.deleteFromLast(2);
    ll.printLL();

    Node *mid = ll.MiddleLL();

    if (mid != NULL)
    {
        cout << "Middle = " << mid->data << endl;
    }
    ll.printLL();
    return 0;
}