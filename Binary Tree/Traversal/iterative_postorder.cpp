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

void printPostorderIterative(TreeNode *root){
    if(root==NULL)
    return ;

    TreeStack treeStack;
    TreeStack storeStack;
    treeStack.push(root);
    while(!treeStack.empty()){

        TreeNode* node = treeStack.top();
        treeStack.pop();
        storeStack.push(node);

        if(node->left!=NULL)
        treeStack.push(node->left);

        if(node->right!=NULL)
        treeStack.push(node->right);
    }

    while(!storeStack.empty()){
        TreeNode* node = storeStack.top();
        storeStack.pop();
        cout<<node->val<<" "; 
    }
}
int32_t main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->right = new TreeNode(6);
    root->left->left->left = new TreeNode(7);
    printPostorderIterative(root);
}