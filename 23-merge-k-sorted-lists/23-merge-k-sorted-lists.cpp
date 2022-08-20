/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct node{
    ListNode* temp;
    int index;
};
class compare{
    public:
    bool operator()(node& a,node& b){
        return (a.temp->val>b.temp->val);
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        ListNode* dummy=new ListNode(0);
        ListNode* newnode=dummy;
        priority_queue<node,vector<node>,compare> pq;
        int n=lists.size();
        for(int i=0;i<n;i++){
            if(lists[i]!=NULL){
            pq.push({lists[i],i});
            }
        }
        while(!pq.empty()){
            node nn=pq.top();
            pq.pop();
              ListNode* n1=new ListNode(nn.temp->val);
             // cout<<nn.temp->val<<endl;
                newnode->next=n1;
            newnode=n1;
            if(nn.temp->next!=NULL){
              
               
                pq.push({nn.temp->next,nn.index});
            }
            
        }
        return dummy->next;
    }
};