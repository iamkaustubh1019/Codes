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
    treeStack.push(root);
    if(root->right!=NULL);
    treeStack.push(root->right);
    TreeNode* node=NULL;
    if(root->left!=NULL)
    node = root->left;
    while(!treeStack.empty()){
        while(node->left!=NULL){
            treeStack.push(node);
            if(node->right!=NULL);
            treeStack.push(node->right);
            node = node->left;
        }
        if(node->right!=NULL){
            node = node->right;
            continue;
        }
        cout<<node->val<<" ";
        node = treeStack.top();
        treeStack.pop();
    }
}
int32_t main(){
    TreeNode* root          = new TreeNode(1);
    root->left              = new TreeNode(2);
    root->right             = new TreeNode(3);
    root->left->left        = new TreeNode(4);
    root->left->right       = new TreeNode(5);
    root->left->left->right = new TreeNode(6);
    root->left->left->left  = new TreeNode(7);
    printPostorderIterative(root);
    /*Perform function Call*/
}