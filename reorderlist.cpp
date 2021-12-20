#include<bits/stdc++.h>
using namespace std;
class node{
	public:
		int data;
	node* next;
		node(int data){
			this->data=data;
			next=NULL;
		}
};

void print(node* head){
	if(!head){
		return;
	}
	cout<<head->data<<" ";
	print(head->next);
}
node* rearrange(node* head){
	if(!head || !head->next){
		return head;
	}
	node* slow=head;
	node* fast=head->next;
	while(fast && fast->next){
		slow=slow->next;
		fast=fast->next->next;
	}
	node* head2=slow->next;
	slow->next=NULL;
	slow=NULL;
	fast=NULL;
	node* curr=head2;
	while(curr){
		fast=curr->next;
		curr->next=slow;
		slow=curr;
		curr=fast;
	}
	node* head1=head;
	head2=slow;
	while(head1&&head2){
		slow=head1->next;
		fast=head2->next;
		head1->next=head2;
		head2->next=slow;
		head1=slow;
		head2=fast;
	}
	return head;
	
}

int main(){
	node* head=new node(1);
	head->next=new node(2);
	head->next->next=new node(3);
	head->next->next->next=new node(4);
		head->next->next->next->next=new node(5);
		print(head);
		cout<<endl;
		head=rearrange(head);
	print(head);
	return 0;
}
