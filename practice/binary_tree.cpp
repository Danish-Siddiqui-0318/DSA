#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        right = left = NULL;
    }
};
static int idx = -1;

Node *buildTree(vector<int> preorder)
{
    idx++;

    if (preorder[idx] == -1)
    {
        return NULL;
    }
    Node *root = new Node(preorder[idx]);
    root->left = buildTree(preorder);  // Left
    root->right = buildTree(preorder); // Right

    return root;
}

// preorder Traversal
void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << endl;
    preOrder(root->left);  // Left
    preOrder(root->right); // right
}

// Inorder Traversal
void InOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left); // Left
    cout << root->data << endl;
    InOrder(root->right); // Right
}

// Post Order

void PostOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << endl;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preorder);
    cout << "Pre Order" << endl;
    preOrder(root);
    cout << endl;
    cout << "In order" << endl;
    InOrder(root);
    cout << endl;
    cout << "Post order" << endl;
    PostOrder(root);
    cout << endl;

    return 0;
}