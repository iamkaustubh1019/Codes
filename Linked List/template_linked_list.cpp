#include<bits/stdc++.h>
using namespace std;

typedef struct ListNode {
    struct ListNode *next;
    int val;
    ListNode (int value){
        val = value;
        next = NULL;
    }
}ListNode;

typedef vector<ListNode *> ListVector;
typedef queue<ListNode *> ListQueue;
typedef stack<ListNode *> ListStack;
typedef unordered_map<ListNode *,int> ListMap;


void  printList(ListNode *head){
    if(head==NULL)
    return ;

    while(head!=NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<"\n";
}

void insert(ListNode * head,int val){
    ListNode *newNode = new ListNode(val);
    while(head->next!=NULL)
        head = head->next;
    head->next = newNode;
}

ListNode* deleteNode(ListNode *head,int val){
    ListNode* node = head;
    if(node->val == val){
        head = head->next;
        return head;
    }
    while(node->next!=NULL){
        if(node->next->val == val)
        {
            node->next = node->next->next;
            return head;
        }
        node = node->next;
    }
    if(node == NULL){
        return head;
    }
    return head;
}

bool isPresentRecursive(ListNode *head,int val){
    
    if(head==NULL)
    return false;

    if(head->val==val)
    return true;

    if(isPresentRecursive(head->next,val))
    return true;

    return false;
}

int findLength(ListNode *head){
    ListNode *node  = head;
    int count = 0;
    while(node!=NULL){
        count++;
        node = node->next;
    }
    return count;
}

int findMid(ListNode *head){
    ListNode *slow = head;
    ListNode *fast = head;
    
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next;
        if(fast->next==NULL)
        break;
        slow = slow->next;
        fast = fast->next;
    }
    return slow->val;
}

int32_t main(){
    int n;
    cin>>n;
    ListNode* head = new ListNode(-1);
    
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        insert(head,a);
    }
    head = head->next;

}
