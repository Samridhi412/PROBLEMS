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
    bool operator()(ListNode* a,ListNode* b){
        return (a->val>b->val);
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        ListNode* dummy=new ListNode(0);
        ListNode* newnode=dummy;
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        int n=lists.size();
        for(int i=0;i<n;i++){
            if(lists[i]!=NULL){
            pq.push(lists[i]);
            }
        }
        while(!pq.empty()){
            ListNode* nn=pq.top();
            pq.pop();
              ListNode* n1=new ListNode(nn->val);
             // cout<<nn.temp->val<<endl;
                newnode->next=n1;
            newnode=n1;
            if(nn->next!=NULL){
              
               
                pq.push(nn->next);
            }
            
        }
        return dummy->next;
    }
};