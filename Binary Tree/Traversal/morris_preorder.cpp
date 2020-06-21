#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode {
    struct TreeNode *left;
    struct TreeNode *right;
    int val;
    TreeNode (int value){
        val = value;
        left = right = NULL;
    }
}TreeNode;

// Inorder
void Morris(TreeNode* root){
    TreeNode* node = root;
    TreeNode* predecesser;
    while(node!=NULL){
        if(node->left==NULL){
            cout<<node->val<<" ";
            node = node->right;
        }
        else{
        predecesser = node->left;
        while(predecesser->right!=NULL && predecesser->right!=node)
        predecesser = predecesser->right;
        if(predecesser->right!=node){
            predecesser->right = node;
            node = node->left;
        }
        else{
            predecesser->right = NULL;
            cout<<node->val<<" ";
            node = node->right;
        }
        }
    }
}

int32_t main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Morris(root);
}