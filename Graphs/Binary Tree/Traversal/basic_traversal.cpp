#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode{
    struct TreeNode* left;
    struct TreeNode* right; 
    int value = 0;
    TreeNode(int value){
        this->value = value;
        this->left = this->right = NULL;
    }
}TreeNode;

void printInorder(TreeNode* root){
    if(root==NULL)
    return ;              

    printInorder(root->left);
    cout<<" "<<root->value<<" ";
    printInorder(root->right);
}

void printPreorder(TreeNode* root){
    if(root==NULL)
    return ;              

    cout<<" "<<root->value<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(TreeNode* root){
    if(root==NULL)
    return ;              

    printPostorder(root->left);
    printPostorder(root->right);
    cout<<" "<<root->value<<" ";
}


int32_t main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout<<"In Order Traversal....\n";
    printInorder(root);
    cout<<"\nPre Order Traversal....\n";
    printPreorder(root);
    cout<<"\nPost Order Traversal....\n";
    printPostorder(root);
}