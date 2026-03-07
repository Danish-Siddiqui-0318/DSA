#include <iostream>
using namespace std;

struct Stack
{
    char data;
    Stack *next;
};

Stack *top = NULL;

void push(char x)
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

int precedence(char x)
{
    switch (x)
    {
    case '*':
    case '/':
    case '%':
        return 6;

    case '+':
    case '-':
        return 5;

    case '<':
    case '>':
        return 4;

    case '&':
        return 3;

    case '|':
        return 2;

    default:
        return 0;
    }
}

bool isOperand(char c)
{
    if (
        (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z') ||
        (c >= '0' && c <='9') )
    {
        return true;
    }
    return false;
}

int main()
{
    char ch;
    string infix = "";
    string postfix="";

    cout << "click 0 to exit input\n";
    while (cin.get(ch) && ch != '0')
    {
        if (ch != '\n')
        {
            infix += ch;
        }
    };

    cout << "Infix:" << infix<<endl;

    for(int i=0;i<infix.length();i++){
        char c=infix[i];
        if(isOperand(c)){
            postfix+=c;
        }else{
            while (top!=NULL && precedence(display())>=precedence(c))
            {
                postfix+=display();
                pop();
            }
            push(c);
        }
    }

    while (top!=NULL)
    {
        postfix+=display();
        pop();
    }

        cout << "Postfix: " << postfix << endl;

    

    return 0;
}
