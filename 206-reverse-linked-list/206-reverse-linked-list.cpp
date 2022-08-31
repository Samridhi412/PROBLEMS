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
    ListNode* recur(ListNode* head){
        if(!head||!head->next){
            return head;
        }
        ListNode* node=recur(head->next);
        head->next->next=head;
        head->next=NULL;
        return node;
        
    }
public:
    ListNode* reverseList(ListNode* head) {
        // ListNode* prev=NULL,*next=NULL;
        // ListNode* curr=head;
        // while(curr){
        //     next=curr->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=next;
        // }
        // return prev;
        return recur(head);
    }
};