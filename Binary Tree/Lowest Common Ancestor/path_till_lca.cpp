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

    if(root->val == first||root->val==second)
    return root;

    TreeNode *left = lca(root->left,first,second);
    TreeNode *right = lca(root->right,first,second);

    if(left!=NULL && right !=NULL)
    return root;
    if(left==NULL && right==NULL)
    return left;
    return (left!=NULL)?left:right;
}
TreeVector findPath(TreeNode *root,int val,TreeVector treeVector){
    if(root==NULL)
    return {};

    if(root->val==val){
        treeVector.push_back(root);
        return treeVector;
    }
    treeVector.push_back(root);

    if(root->left!=NULL){
        TreeVector treeVectorLeft = findPath(root->left,val,treeVector);
        if(treeVectorLeft.size()){
            if(treeVectorLeft.back()->val == val)
            return treeVectorLeft;
        } 
    }

    if(root->right!=NULL){
        TreeVector treeVectorRight = findPath(root->right,val,treeVector);
        if(treeVectorRight.size()){
            if(treeVectorRight.back()->val == val)
            return treeVectorRight;
        }
    }

    return {};
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
    insertBST(root,17);

    /*Function Call*/
    int a,b;
    cin>>a>>b;
    TreeNode* node = lca(root,a,b);
    cout<<"Ancestor is : "<<node->val<<"\n";
    TreeVector treeVector = findPath(root,node->val,{});
    for(int i=0;i<treeVector.size();i++)
    cout<<treeVector[i]->val<<" ";
}