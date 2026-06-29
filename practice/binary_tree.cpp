#include <iostream>
#include <vector>
using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *left;
//     Node *right;

//     Node(int val)
//     {
//         data = val;
//         right = left = NULL;
//     }
// };
// static int idx = -1;

// Node *buildTree(vector<int> preorder)
// {
//     idx++;

//     if (preorder[idx] == -1)
//     {
//         return NULL;
//     }
//     Node *root = new Node(preorder[idx]);
//     root->left = buildTree(preorder);  // Left
//     root->right = buildTree(preorder); // Right

//     return root;
// }

// // preorder Traversal // NLR
// void preOrder(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     cout << root->data << endl;
//     preOrder(root->left);  // Left
//     preOrder(root->right); // right
// }

// // Inorder Traversal // LNR
// void InOrder(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     InOrder(root->left); // Left
//     cout << root->data << endl;
//     InOrder(root->right); // Right
// }

// // Post Order //LRN

// void PostOrder(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     PostOrder(root->left);
//     PostOrder(root->right);
//     cout << root->data << endl;
// }

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
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
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

void preOrder(Node *root)
{ // NLR
    if (root == NULL)
    {
        return;
    }
    cout << root->data << endl;
    preOrder(root->left);
    preOrder(root->right);
}

void InOrder(Node *root)
{ // LNR
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    cout << root->data << endl;
    InOrder(root->right);
}

void PostOrder(Node *root)
{ // LRN
    if (root == NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << endl;
}

// Height of trees

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

// Count Nodes

int countNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);
    return leftCount + rightCount + 1;
}

int sumNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftSum = sumNodes(root->left);
    int rightSum = sumNodes(root->right);
    return leftSum + rightSum + root->data;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildTree(preorder);

    cout << "Preorder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Inorder Traversal : ";
    InOrder(root);
    cout << endl;

    cout << "Postorder Traversal : ";
    PostOrder(root);
    cout << endl;

    cout << "Height of Tree : " << height(root) << endl;
    cout << "Total Nodes : " << countNodes(root) << endl;
    cout << "Sum of Nodes : " << sumNodes(root) << endl;

    return 0;
}
