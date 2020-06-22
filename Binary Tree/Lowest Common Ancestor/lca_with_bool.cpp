#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode {
    struct TreeNode *left;
    struct TreeNode *right;
    int val;
    bool inPath;
    TreeNode (int value){
        val = value;
        left = right = NULL;
        inPath = false;
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

bool findFirst(TreeNode* root,int val){
    if(root == NULL)
    return false;

    if(root->val == val){
        root->inPath = true;
        return true;
    }

    else if(findFirst(root->left,val)||findFirst(root->right,val)){
        root->inPath = true;
        return true;
    }
    return false;
}

bool findSecond(TreeNode *root,int val,bool &printed){
    if(root == NULL)
    return false;

    if(root->val == val){
        return true;
    }

    if(findSecond(root->left,val,printed)||findSecond(root->right,val,printed)){
        if(!printed && root->inPath){
            printed = true;
            cout<<root->val;
        }
        return true;
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
    findFirst(root,a);
    findSecond(root,b,c);
}