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

int findHeight(TreeNode* root){

    if(root==NULL)
    return 0;

    int lheight = findHeight(root->left);
    int rheight = findHeight(root->right);
    return max(lheight+1,rheight+1);
}

void printForGivenLevel(TreeNode* node,int level,bool opposite){
    if(node==NULL)
    return ;

    if(level==1)
    cout<<node->val<<" ";

    else if(opposite){
        printForGivenLevel(node->left,level-1,opposite);
        printForGivenLevel(node->right,level-1,opposite);
    }
    else{
        printForGivenLevel(node->right,level-1,opposite);
        printForGivenLevel(node->left,level-1,opposite);
    }
}



int32_t main(){

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    int h = findHeight(root);

    for(int i=1;i<=h;i++){
    printForGivenLevel(root,i,i%2!=0);
    }
}