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
bool leastCommonAncestor(TreeNode* root,int val,int lvalue,int rvalue,bool &printed){
    if(root==NULL)
    return false;
    if(val == root->val)
    return true;
    bool l1= leastCommonAncestor(root->left,lvalue,lvalue,rvalue,printed);
    bool l2= leastCommonAncestor(root->left,rvalue,lvalue,rvalue,printed);
    bool flagL = l1 || l2;
    bool r1 = leastCommonAncestor(root->right,rvalue,lvalue,rvalue,printed);
    bool r2 = leastCommonAncestor(root->right,lvalue,lvalue,rvalue,printed);
    bool flagR = r1 || r2;
    if(flagL && flagR && !printed){
    	cout<<root->val;
    	printed=true;
    }
    else if(flagL && (root->val == rvalue || root->val == lvalue) && !printed){
    	cout<<root->val;
    	printed=true;
    }
    else if(flagR && (root->val == lvalue || root->val == rvalue) && !printed){
    	cout<<root->val;
    	printed=true;
    }
    return false;
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
    bool c;
    leastCommonAncestor(root,-1,a,b,c);
}