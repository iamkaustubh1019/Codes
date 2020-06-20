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

void printLeverOrder(TreeNode* root){
    queue<TreeNode *> treeQueue;
    treeQueue.push(root);
    while(!treeQueue.empty()){
        root = treeQueue.front();
        cout<<" "<<root->value<<" ";
        treeQueue.pop();

        if(root->left!=NULL)
        treeQueue.push(root->left);

        if(root->right!=NULL)
        treeQueue.push(root->right);
    }

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
    root->left->left->right = new TreeNode(6);
    root->left->left->left = new TreeNode(7);
    cout<<"\nPost Order Traversal....\n";
    printPostorder(root);
    cout<<"\n";
    printLeverOrder(root);
   
}