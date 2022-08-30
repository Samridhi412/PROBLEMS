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
class Solution {
    ListNode* getmid(ListNode* head){
        ListNode* slow=NULL;
        while(head&&head->next){
            slow=(slow==NULL)?head:slow->next;
            head=head->next->next;
        }
        ListNode* mid=slow->next;
        slow->next=NULL;
        return mid;
    }
    ListNode* merge(ListNode* left,ListNode* right){
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        while(left&&right){
            if(left->val<right->val){
                tail->next=left;
                left=left->next;
            }
            else{
                tail->next=right;
                right=right->next;
            }
            tail=tail->next;
        }
        if(left)tail->next=left;
        if(right)tail->next=right;
        return dummy->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* mid=getmid(head);
        ListNode* left=sortList(head);
        ListNode* right=sortList(mid);
        return merge(left,right);
    }
};