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
typedef pair<int,int> IntPair;

void insertBST(TreeNode *root,int val){
    if(root==NULL)
    root = new TreeNode(val);
    
    else if(val<root->val){
        if(root->left==NULL)
        root->left = new TreeNode(val);
        else
        insertBST(root->left,val);
    }
    else{
        if(root->right==NULL)
        root->right = new TreeNode(val);
        else
        insertBST(root->right,val);
    }
}


int maxDiff(TreeNode *root,int &maxDifference){
    if(root==NULL)
    return INT_MAX;

    if(root->left==NULL && root->right==NULL)
    return root->val;

    int val = min(maxDiff(root->left,maxDifference),maxDiff(root->right,maxDifference));
    maxDifference = max(maxDifference,root->val-val);
    return min(val,root->val);
}
int32_t main(){
    TreeNode* root = new TreeNode(10);
    insertBST(root,7);
    insertBST(root,6);
    insertBST(root,8);
    insertBST(root,9);
    insertBST(root,4);
    insertBST(root,5);
    insertBST(root,3);
    insertBST(root,2);
    insertBST(root,1);
    insertBST(root,2);
    insertBST(root,15);
    insertBST(root,11);
    insertBST(root,13);
    insertBST(root,12);
    insertBST(root,14);
    insertBST(root,16);
    insertBST(root,20);
    insertBST(root,18);
    insertBST(root,21);
    insertBST(root,19);
    insertBST(root,17);

    /*Function Call*/
    int a = INT_MIN;
    maxDiff(root,a);
    cout<<a;
}