#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
    node(int val){
        data=val;
        left=right=NULL;
    }
};

void preorder(node* ptr){
    if(ptr==NULL){
        return;
    }
    cout<<ptr->data;
    preorder(ptr->left);
    preorder(ptr->right);
}
// t.c. O(n)
// s.c. O(n)    recursive stack space

void inorder(node* ptr){
    if(ptr==NULL){
        return;
    }
    inorder(ptr->left);
    cout<<ptr->data;
    inorder(ptr->right);
}

void postorder(node* ptr){
    if(ptr==nullptr){
        return;
    }
    postorder(ptr->left);
    postorder(ptr->right);
    cout<<ptr->data;
}

int main() {
    struct node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->right=new node(5);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
}