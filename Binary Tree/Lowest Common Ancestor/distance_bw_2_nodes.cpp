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
TreeNode* lca(TreeNode* root,int first,int second){
    if(root==NULL)
    return root;

    if(root->val == first||root->val == second)
    return root;

    TreeNode *left = lca(root->left,first,second);
    TreeNode *right = lca(root->right,first,second);

    if(left!=NULL && right!=NULL){
        return root;
    }
    if(left == NULL && right == NULL){
        return left;
    }
    return (left!=NULL)?left:right;
}

int findDistance(TreeNode* root,int val){
    if(root==NULL)
    return -100;
   
    if(root->val == val)
    return 0;
    
    int lheight=INT_MIN,rheight=INT_MIN;
    if(root->left)
    lheight = findDistance(root->left,val);
    if(root->right)
    rheight = findDistance(root->right,val);

    return max(lheight,rheight)+1;
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

    /*Function Call*/
    int a,b;
    cin>>a>>b;
    TreeNode* node = lca(root,a,b);
    cout<<findDistance(node,a)<<"+";
    cout<<findDistance(node,b);
} 