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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1&&!l2)return NULL;
       else if(!l1)return l2;
        else if(!l2)return l1;
        int sum=l1->val+l2->val;
        ListNode* node=new ListNode(sum%10);
        node->next=addTwoNumbers(l1->next,l2->next);
        if(sum>9){
            node->next=addTwoNumbers(new ListNode(1),node->next);
        }
        return node;
    }
};