#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data=value;
        right=left=NULL;
    }
};

Node* findMin(Node* root){
    while (root && root->left !=NULL)
    {
        root=root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int value){
    if(root ==NULL){
        return NULL;
    }
    if(value<root->data){
        root->left=deleteNode(root->left,value);
    }else if(value>root->data){
        root->right=deleteNode(root->right,value);
    }else{
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        if(root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }else if(root->right == NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }

        Node* temp=findMin(root->right);
        root->data=temp->data;
        root->right =deleteNode(root->right , temp->data);
    }
    return root;
}

Node* insert(Node* root,int value){
    if(root==NULL){
        return new Node(value);
    }

    if(value<root->data){
        root->left=insert(root->left,value);
    }else if(value>root->data){
        root->right=insert(root->right,value);
    }
    return root;
}

Node* search(Node* root,int value){
    if(root==NULL || root->data==value){
        return root;
    }

    if(value<root->data){
        return search(root->left,value);
    }else if(value>root->data){
        return search(root->right,value);
    }
}

int main(){
    Node *root=NULL;
    root=insert(root,10);
    root=insert(root,5);
    root=insert(root,15);
    root=insert(root,3);
    root=insert(root,7);

    Node* found=search(root,7);

    if(found!=NULL){
        cout<<"Value Found!";
    }else{
        cout<<"Value Not Found";
    }

    root=deleteNode(root,5);

    return 0;
}