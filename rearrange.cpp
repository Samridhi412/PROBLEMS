#include<iostream>
 #include<math.h>
using namespace std;
class node
{
	public:
	int data;
	node *next=NULL;
	node(int data)
	{
		this->data=data;
	}
};
node *insert()
{
	node *head=NULL;
	node *tail=NULL;
	int data;
	cout<<"enter the value\n";
	cin>>data;
	while(data!=-1)
	{
	node *newnode=new node(data);
		if(head==NULL)
		{
			head=newnode;
			tail=newnode;
		}
		else
		{
		tail->next=newnode;
		tail=newnode;	
		}
		cin>>data;
	}
	return head;
	}
	void print(node *head)
	{
		while(head!=NULL)
		{
			cout<<head->data<<" ";
			head=head->next;
		}
	}
	int length(node *head)
	{
		int count=0;
		while(head!=NULL)
		{
			count++;
			head=head->next;
		}
		return count;
	}
     void rearrange(node *head)
	{
	node *temp=head;
	node *temp1=head->next;
	int len=length(head);
	if(len%2==0)
	{
		while(temp->next->next!=NULL)
		{
		temp->next=temp->next->next;
		temp=temp->next->next;
			}
			node *a=temp;
			a->next=temp1;
			while(temp1->next!=NULL)
			{
				temp1->next=temp1->next->next;
				temp1=temp1->next->next;
				}
					}
					else
					{
							while(temp->next!=NULL)
			{
				temp->next=temp->next->next;
				temp=temp->next->next;
				}
				node *b=temp;
				b->next=temp1;
				while(temp1->next->next!=NULL)
		{
		temp1->next=temp1->next->next;
		temp1=temp1->next->next;
			}
				
					}
				}
				int main()
	{
	node *head=insert();
	print(head);
	rearrange(head);
	print(head);
	return 0;
}
