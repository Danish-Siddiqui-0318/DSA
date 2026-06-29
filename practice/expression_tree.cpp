#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    char data;
    Node *left;
    Node *right;

    Node(char val)
    {
        data = val;
        left = right = NULL;
    }
};

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

Node *buildExpressionTree(string postfix)
{
    stack<Node *> st;
    for (char ch : postfix)
    {
        if (!isOperator(ch))
        {
            st.push(new Node(ch));
        }
        else
        {
            Node *right = st.top();
            st.pop();
            Node *left = st.top();
            st.pop();
            Node *newNode = new Node(ch);
            newNode->left = left;
            newNode->right = right;
            st.push(newNode);
        }
    }
    return st.top();
}

void PreOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void InOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void PostOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    string postfix = "abc*+de/f+gh-*-ij*+kl+mn*-/";

    Node *root = buildExpressionTree(postfix);

    cout << "Prefix : ";
    PreOrder(root);
    cout << endl;

    cout << "Infix : ";
    InOrder(root);
    cout << endl;

    cout << "Postfix : ";
    PostOrder(root);
    cout << endl;

    return 0;
}