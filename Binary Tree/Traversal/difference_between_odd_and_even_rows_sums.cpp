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

int getLevelDiff(TreeNode *root)
{
    if(root==NULL)
    return 0;
    
    return root->value - getLevelDiff(root->left) - getLevelDiff(root->right);
}


int32_t main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->right = new TreeNode(6);
    root->left->left->left = new TreeNode(7);
    cout<<getLevelDiff(root);
}

