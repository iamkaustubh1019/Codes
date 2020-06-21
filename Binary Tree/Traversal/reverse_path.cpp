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
    
    if(node==NULL)
    return treeVector;

    if(node->val == target){
        treeVector.push_back(node);
        return treeVector;
    }

    if(node->left==NULL && node->right==NULL)
    return treeVector;

    TreeVector newTreeVectorLeft;
    TreeVector newTreeVectorRight;
    treeVector.push_back(node);

    if(node->left!=NULL){
        newTreeVectorLeft = findPath(node->left,target,treeVector);
        if(newTreeVectorLeft.back()->val == target)
        return newTreeVectorLeft;
    }
    if(node->right!=NULL){
        newTreeVectorRight = findPath(node->right,target,treeVector);
        if(newTreeVectorRight.back()->val == target)
        return newTreeVectorRight;
    }
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
    int a;
    cin>>a;
    treeVector = findPath(root,a,treeVector);
    int size = treeVector.size();
    cout<<size<<" ";
    for(int i=0;i<size/2;i++){
        swap(treeVector[i]->val,treeVector[size-1-i]->val);
    }
    printInorder(root);

}