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

int MIN = INT_MAX;
int MAX = INT_MIN;
typedef unordered_map<TreeNode *,int> Map;

void verticalTraversal( Map &umap,TreeNode* node,int val){
    if(node==NULL)
    return ;

    MIN = min(MIN,val);
    MAX = max(MAX,val); 
    umap[node] = val;
    verticalTraversal(umap,node->left,val-1);
    verticalTraversal(umap,node->right,val+1);
}


int32_t main(){

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Map umap;
    verticalTraversal(umap,root,0);
    for(int i=MIN ; i<=MAX ; i++ ){
        for(auto node:umap){
            if(node.second==i)
            cout<<" "<<node.first->val<<" ";
        }
        cout<<"\n";
    }
}