/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return NULL;
        Node* temp=head;
        Node* front=head;
        while(temp){
            front=temp->next;
            Node* node1=new Node(temp->val);
            temp->next=node1;
            node1->next=front;
            temp=front;
        }
        
        temp=head;
        while(temp){
            if(temp->random){
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }
        temp=head;
        Node* newhead=new Node(0);
        Node* copy=newhead;
        while(temp){
            // cout<<"here"<<endl;
            Node* front=temp->next->next;
            copy->next=temp->next;
            temp->next=front;
            temp=temp->next;
            copy=copy->next;
            
        }
        return newhead->next;
    }
};