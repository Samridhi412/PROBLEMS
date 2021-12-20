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
node *insert(int data)
{
	node *head=NULL;
	node *tail=NULL;
	/*int data;
	cout<<"enter the value\n";
	cin>>data;*/
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
/*	node *nodeatn(node *head,int data,int n)
	{
			int len=length(head);
			if(n>len)
			{
				cout<<"node cannot be inserted\n"<<endl;
				return NULL;
			}
				node *newnode=new node(data);
				if(n==0)
				{
					newnode->next=head;
					return newnode;
				}
				else
				{
					node *temp=head;
					int count=0;
					while(count<n-1)
					{
						count++;
						temp=temp->next;
					}
					node *a=temp->next;
					temp->next=newnode;
					newnode->next=a;
					return head;
				}
	}*/
	/*node *deleteatn(node *head,int pos)
	{
		int len=length(head);
		if(pos>=len)
			{
				cout<<"node cannot be deleted\n"<<endl;
				return NULL;
			}
		if(pos==0)
				{
					node *temp=head;
					head=head->next;
					delete(temp);
					return head;
				}
				else
				{
					node *temp=head;
					int count=0;
					while(count<pos-1)
					{
						count++;
						temp=temp->next;
					}
					node *a=temp->next;
					temp->next=a->next;
					delete(a);
					return head;
				}
	}*/
	/*node *swapping(int i,int j,node *head)
	{
	node *temp=head;
	for(int m=0;m<i;m++)
	{
		temp=temp->next;
	}
	int c=temp->data;
	temp=head;
	for(int n=0;n<j;n++)
	{
		temp=temp->next;
	}
	int d=temp->data;
	int swap;
	swap=c;
	c=d;
	d=swap;
	temp=head;
	for(int k=0;k<i;k++)
	{
		temp=temp->next;
	}
	temp->data=c;
	temp=head;
	for(int l=0;l<j;l++)
	{
		temp=temp->next;
	}
	temp->data=d;
	return head;
		}
		node* swap_nodes(node *head,int i,int j)
{
    node *p1=NULL, *n1=NULL, *p2=NULL, *n2 = NULL, *temp = head, *prev =NULL;
    int pos=0;

    while(temp!=NULL)
    {
        if(pos==i)
        {
            p1=prev;
            n1=temp;
        }
        if(pos==j)
        {
            p2=prev;
            n2=temp;
        }
        prev = temp;
        temp = temp->next;
        pos++;
    }
    if(p1==NULL)
    {
        head = n2;
        p2->next=n1;
        node *temp = n1->next;
        n1->next=n2->next;
        n2->next=temp;
       return head;
    }
    else
    {
        p1->next = n2;
        p2->next=n1;
        n1->next=n2->next;
        n2->next=p2;

    return head;
    }
    if(p2==NULL)
    {
        head = n1;
        p1->next=n2;
        n2->next=n1->next;
        n1->next=p1;
        return head;
    }
    else
    {
        p2->next = n1;
        p1->next=n2;
        n2->next=n1->next;
        n1->next=p1;
        return head;
    }
    
    //idhar ek baar mei he kar lenge sara
    node *t = n1->next;
    n1->next = n2->next;
    n2->next = t;
    return head;
}
		void midpoint(node * head)
		{
			int len=length(head);
			int mid=(len-1)/2;
			node *temp=head;
			for(int i=0;i<mid;i++)
			{
				temp=temp->next;
			}
			cout<<"mid of linked list is\n"<<temp->data<<endl;
		}
		node *bubblesort(node *head)
		{
		int len=length(head);
			node *temp=head;
			node *a=NULL;
		for(int i=0;i<len-1;i++)
		{
			while(temp->next->next!=NULL||temp!=a)
			{
				if(temp->data>temp->next->data)
				{
					swapping(temp->data,temp->next->data,head);
				}
				
				temp=temp->next;
			}
			node *a=temp;
			}
			return head;	
		}*/
		/*node *deletennodesaftermnodes(node *head,int m,int n)
		{
		
		node *temp=head;
		int count=0;
		while(temp!=NULL)
		{
			cout<<temp->data<<endl;
			for(int i=1;i<m;i++)
			{
				temp=temp->next;
				count++;
				cout<<temp->data<<endl;
			}
			node *a=temp;
			for(int j=1;j<=n;j++)
			{
				temp=temp->next;
				count++;
				deleteatn(head,++count);
			}
			node *b=temp->next;
			count++;
			a->next=b;
		}
		return head;
			
		}*/
		void addonetolinkedlist(node *head)
		{
			int len=length(head);
			node *temp=head;
			int sum=0;
			while(temp!=NULL)
			{
			sum+=temp->data*pow(10,len-1);
			temp=temp->next;
			len--;
			}
			sum+=1;
			while(sum>0)
			{
				int rem=sum%10;
				sum=sum/10;
				head=insert(rem);
				
			}
			
		}
	int main()
	{
	node *head=insert(1);
	head=insert(9);
	head=insert(8);
	head=insert(5);
	head=insert(9);
	print(head);
/*	int len=length(head);
	cout<<"length of linked list is"<<" "<<len<<endl;
	int pos,value,x;
	cout<<"enter the position where node is to be inserted\n";
	cin>>pos;
	cout<<"enter the value to be inserted\n";
	cin>>value;
	head=nodeatn(head,value,pos);
	print(head);
	cout<<"enter the position to delete\n";
	cin>>x;
	head=deleteatn(head,x);
	print(head);
	int a,b,m,n;
	cout<<"enter the positions to swap\n";
	cin>>a>>b;
	swapping(a,b,head);
	cout<<"linked list after swapping is\n";
		print(head);
		midpoint(head);
			cout<<"enter the positions to swap by links\n";
			
	cin>>m>>n;
	
	cout<<"swapping function called\n";
	head=swap_nodes(head,m,n);
		cout<<"linked list after swapping by links\n";
	print(head);
//	head=bubblesort(head);
	//print(head);*/
	//int m,n;
	//cout<<"enter the value of m and n\n";
	//cin>>m>>n;
	//deletennodesaftermnodes(head,m,n);
	addonetolinkedlist(head);
		print(head);
	return 0;	
	}
