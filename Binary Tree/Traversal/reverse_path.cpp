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
typedef vector<TreeNode *> TreeVector;

TreeVector findPath(TreeNode *node,int target,TreeVector treeVector){
    if(node->val == target){
        treeVector.push_back(node);
        return treeVector;
    }

    treeVector.push_back(node);
    treeVector = findPath(node->left,target,treeVector);
    if(treeVector.back()->val == target)
    return treeVector;
    treeVector = findPath(node->right,target,treeVector);
    if(treeVector.back()->val == target)
    return treeVector;

    return treeVector;
}
void printInorder(TreeNode* root){
    if(root==NULL)
    return ;              

    printInorder(root->left);
    cout<<" "<<root->val<<" ";
    printInorder(root->right);
}

int32_t main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->right = new TreeNode(6);
    root->left->left->left = new TreeNode(7);
    TreeVector treeVector;
    treeVector = findPath(root,7,treeVector);
    int size = treeVector.size();
    for(int i=0;i<size/2;i++){
        swap(treeVector[i]->val,treeVector[size-1-i]->val);
    }
    printInorder(root);

}