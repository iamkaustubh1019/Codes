#include<bits/stdc++.h>
using namespace std;

int findPosition(int *in,int x,int n){
    for(int i=0;i<n;i++){
        if(in[i]==x)
        return i;
    }
    return -1;
}

void printPostOrder(int in[],int pre[],int n){
    int root_index = findPosition(in,pre[0],n);
    // if root_index = 0 that means root in inorder array is the first element and left subtree is empty.
    // if root_index = n-1 that means root in inorder array is the last element and right subtree is empty. 
    // So we are basically visiting a left subtree.
    // In array when you do something like this:
    // arr = {1,2,3,4,5}
    // arr + 1 = {2,3,4,5}
    // Basically its the subset.
    // Now We will be taking in first elemt of current preorder array and find the index of that subtree in inorder array.
    // This we will do in reccursion as follows.
    if(root_index!=0){
        printPostOrder(in,pre+1,root_index);
    }

    if(root_index!=n-1){
        printPostOrder(in+root_index+1,pre+root_index+1,n-1-root_index);
    }

    // the code reaches here when all the node is leaf node or the subtrees to this root is traversed.
    cout<<pre[0]<<" ";
}

int32_t main(){
    int in[] = { 4, 2, 5, 1, 3, 6 }; 
    int pre[] = { 1, 2, 4, 5, 3, 6 }; 
    int n = sizeof(in) / sizeof(in[0]); 
    cout << "Postorder traversal " << endl; 
    printPostOrder(in, pre, n); 
}