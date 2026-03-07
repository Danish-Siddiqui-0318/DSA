#include <iostream>
using namespace std;

struct Stack
{
    int data;
    Stack *next;
};

Stack *top = NULL;

void push(int x)
{
    Stack *newStack = new Stack();
    newStack->data = x;
    newStack->next = top;
    top = newStack;
}

void pop()
{
    if (top == NULL)
    {
        cout << "Stack underflow" << endl;
        return;
    }
    Stack *temp = top;
    top = top->next;
    delete temp;
}

int display()
{
    if (top == NULL)
    {
        return -1;
    }
    return top->data;
}

int main()
{
    push(56);
    push(20);
    push(26);
    cout << display() << endl;
    pop();
    cout << display() << endl;

    return 0;
}

// #define SIZE 10

// struct Stack
// {
//     int arr[SIZE];
//     int top;
// };

// Stack s;

// void init()
// {
//     s.top -= -1;
// }

// void push(int value)
// {
//     if (s.top == SIZE - 1)
//     {
//         cout << "Stack Overflowed";
//         return;
//     }

//     s.top++;
//     s.arr[s.top] = value;
// }

// void pop()
// {
//     if (s.top == -1)
//     {
//         cout << "Stack underflow";
//         return;
//     }

//     cout << "Popped" << s.arr[s.top] << endl;
//     s.top--;
// }

// void display()
// {
//     if (s.top == -1)
//     {
//         cout << "Stack is empty";
//         return;
//     }

//     cout << "Stack elements"<<endl;
//     for (int i = s.top; i >= 0; i--)
//     {
//         cout << s.arr[i] << endl;
//     }
// }

// int main(){
//     init();
//     push(10);
//     push(20);
//     push(30);

//     display();
//     pop();
//     display();   
// }