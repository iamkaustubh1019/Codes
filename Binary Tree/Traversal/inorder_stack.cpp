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

void inorder_stack_map(TreeNode *root) {
    if(root == NULL)
    return ;

    stack <TreeNode *> treeStack;
    unordered_map<TreeNode *,bool> umap;
    treeStack.push(root);
    umap[root] = true;
    TreeNode* head = root;

    while(!treeStack.empty()){
       TreeNode* node = treeStack.top();
       if(node->left==NULL && node->right==NULL){
           cout<<node->val<<" ";
           treeStack.pop();
       }
       else if(node->left!=NULL && !umap[node->left])
       {
           treeStack.push(node->left);
           umap[node->left] = true;
       }
       else if(node->right!=NULL && !umap[node->right]){
           cout<<node->val<<" ";
           treeStack.pop();
           treeStack.push(node->right);
           umap[node->right] = true;
       }
       else{
            cout<<node->val<<" ";
            treeStack.pop();
       }
    }
}

void inorder_stack(TreeNode *root){

    if(root == NULL)
    return ;

    TreeNode* node = root;
    stack<TreeNode *> treeStack;
    while(node!=NULL || !treeStack.empty()){
        while(node!=NULL){
            treeStack.push(node);
            node = node->left;
        }
        node  = treeStack.top();
        treeStack.pop();
        cout<<" "<<node->val<<" ";
        node = node->right;
    }
}

int32_t main(){

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    inorder_stack(root);
}