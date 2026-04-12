#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Tree Node
struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char val) {
        data = val;
        left = right = NULL;
    }
};

// Check operator
bool isOp(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Precedence function
int getPriority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Build Expression Tree from Infix
Node* buildTree(string infix) {
    stack<Node*> nodes;
    stack<char> ops;

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        // Operand
        if (isalnum(ch)) {
            nodes.push(new Node(ch));
        }
        // Opening bracket
        else if (ch == '(') {
            ops.push(ch);
        }
        // Closing bracket
        else if (ch == ')') {
            while (!ops.empty() && ops.top() != '(') {
                char op = ops.top(); ops.pop();

                Node* right = nodes.top(); nodes.pop();
                Node* left = nodes.top(); nodes.pop();

                Node* newNode = new Node(op);
                newNode->left = left;
                newNode->right = right;

                nodes.push(newNode);
            }
            ops.pop(); // remove '('
        }
        // Operator
        else if (isOp(ch)) {
            while (!ops.empty() && getPriority(ops.top()) >= getPriority(ch)) {
                char op = ops.top(); ops.pop();

                Node* right = nodes.top(); nodes.pop();
                Node* left = nodes.top(); nodes.pop();

                Node* newNode = new Node(op);
                newNode->left = left;
                newNode->right = right;

                nodes.push(newNode);
            }
            ops.push(ch);
        }
    }

    // Remaining operators
    while (!ops.empty()) {
        char op = ops.top(); ops.pop();

        Node* right = nodes.top(); nodes.pop();
        Node* left = nodes.top(); nodes.pop();

        Node* newNode = new Node(op);
        newNode->left = left;
        newNode->right = right;

        nodes.push(newNode);
    }

    return nodes.top();
}

// Traversals
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}

int main() {
    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    Node* root = buildTree(infix);

    cout << "\nInorder   : ";
    inorder(root);

    cout << "\nPreorder  : ";
    preorder(root);

    cout << "\nPostorder : ";
    postorder(root);

    return 0;
}