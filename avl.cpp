#include <iostream>
#include <algorithm>
using namespace std;

struct AVLNode
{
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;


    AVLNode(int val){
        data=val;
        left=right=NULL;
        height=1;
    }
};

int getHeight(AVLNode* node){
    if(node==NULL) return 0;
    return node->height;
}

int getBalance(AVLNode* node){
    if(node==NULL)return 0;
    return getHeight(node->left)-getHeight(node->right);
}

AVLNode* rotateRight(AVLNode* y){
    AVLNode* x=y->left;
    AVLNode* T2=x->right;

    x->right=y;
    y->left=T2;

    y->height=max(getHeight(y->left),getHeight(y->right))+1;
    x->height=max(getHeight(x->left),getHeight(x->right))+1;

    return x;
}

AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

AVLNode* insertAVL(AVLNode* node,int value){
    if(node==NULL){
        return new AVLNode(value);
    }

    if(value < node->data){
        node->left = insertAVL(node->left,value);
    } 
    else if(value > node->data){
        node->right = insertAVL(node->right,value);
    } 
    else{
        return node;
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    if(balance > 1 && value < node->left->data){
        return rotateRight(node);
    }

    if(balance < -1 && value > node->right->data){
        return rotateLeft(node);
    }

    if(balance > 1 && value > node->left->data){
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if(balance < -1 && value < node->right->data){
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void inorder(AVLNode* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    AVLNode* root = NULL;

    root = insertAVL(root, 10);
    root = insertAVL(root, 20);
    root = insertAVL(root, 30);
    root = insertAVL(root, 25);
    root = insertAVL(root, 5);

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}
