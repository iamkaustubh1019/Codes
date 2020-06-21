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

typedef stack<TreeNode *> TreeStack;
typedef queue<TreeNode *> TreeQueue;
typedef vector<TreeNode *> TreeVector;
typedef unordered_map<TreeNode*,int> TreeMap;

void printPreorderIterative(TreeNode* root){
    if(root==NULL)
    return;
    TreeStack treeStack;
    treeStack.push(root);

    while(!treeStack.empty()){
        TreeNode* node = treeStack.top();
        treeStack.pop();
        cout<<node->val<<" ";
        if(node->right!=NULL)
        treeStack.push(node->right);
        if(node->left!=NULL)
        treeStack.push(node->left);
    }
}

int32_t main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    printPreorderIterative(root);
}