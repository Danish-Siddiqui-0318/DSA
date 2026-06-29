#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;
    int height;

    Node(int val)
    {
        data = val;
        right = left = NULL;
        height = 1;
    }
};

// int getHeight(Node *node)
// {
//     if (node == NULL)
//     {
//         return 0;
//     }
//     return node->height;
// }
int getHeight(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}
// int getBalance(Node *node)
// {
//     if (node == NULL)
//     {
//         return 0;
//     }
//     return getHeight(node->left) - getHeight(node->right);
// }
int getBalance(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// // right Rotation
// Node *rotateRight(Node *y)
// {
//     Node *x = y->left;
//     Node *T2 = x->right;

//     x->right = y;
//     y->left = T2;

//     y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
//     x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

//     return x;
// }

Node *rotateRight(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

// Node *rotateLeft(Node *x)
// {
//     Node *y = x->right;
//     Node *T2 = y->left;

//     y->left = x;
//     x->right = T2;

//     x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
//     y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

//     return y;
// }
Node *rotateLeft(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

// Node *insert(Node *root, int val)
// {
//     if (root == NULL)
//     {
//         return new Node(val);
//     }

//     if (val < root->data)
//     {
//         root->left = insert(root->left, val);
//     }
//     else if (val > root->data)
//     {
//         root->right = insert(root->right, val);
//     }
//     else
//     {
//         return root;
//     }

//     root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

//     int balance = getBalance(root);

//     // 4 Cases
//     // LL
//     if (balance > 1 && val < root->left->data)
//     {
//         return rotateRight(root);
//     }
//     // RR
//     if (balance < -1 && val > root->right->data)
//     {
//         return rotateLeft(root);
//     }
//     // LR
//     if (balance > 1 && val > root->left->data)
//     {
//         root->left = rotateLeft(root->left);
//         return rotateRight(root);
//     }
//     if (balance < -1 && val < root->right->data)
//     {
//         root->right = rotateRight(root->right);
//         return rotateLeft(root);
//     }
//     return root;
// }
Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val);
    }
    else
    {
        return root;
    }
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int balance = getBalance(root);
    // 4 Cased
    // LL
    if (balance > 1 && val < root->left->data)
    {
        return rotateRight(root);
    }
    // RR
    if (balance < -1 && val > root->right->data)
    {
        return rotateLeft(root);
    }
    // LR
    if (balance > 1 && val > root->left->data)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && val < root->right->data)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}
// Node *buildAVL(vector<int> arr)
// {
//     Node *root = NULL;

//     for (int val : arr)
//     {
//         root = insert(root, val);
//     }
//     return root;
// }

Node *buildAVL(vector<int> arr)
{
    Node *root = NULL;
    for (int val : arr)
    {
        root = insert(root, val);
    }
    return root;
}

void InOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    cout << root->data << endl;
    InOrder(root->right);
}

int main()
{
    vector<int> arr = {10, 20, 30, 25, 5};

    Node *root = buildAVL(arr);

    cout << "AVL Inorder: ";
    InOrder(root);
    cout << endl;

    return 0;
}