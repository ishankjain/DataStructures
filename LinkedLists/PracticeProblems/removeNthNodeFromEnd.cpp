//Remove Nth Node From End of List

#include<iostream>
using namespace std;


class node
{
	
public:
	int data;
	node* next;
};
class linkedlist
{
	node *head;
public:
    int size;
	linkedlist()
	{
		head=NULL;
		size=0;
	}
	node* gethead()
	{
		return head;
	}
	void insert(int pos,int value)
	{
		node* temp;
		temp=new node;
		temp->data=value;
		temp->next=NULL;
		node* i;
		i=head;
		if(pos==1)
		{
			temp->next=head;
			head=temp;
			size++;
			return;
		}
		if(pos>size+1)
		{
			cout<<"wrong position";
			return;
		}
		--pos;
		while(--pos)
		{
			i=i->next;
		}
		temp->next=i->next;
		i->next=temp;
	    size++;
	}
	void display()
	{
		node* temp;
		temp=head;
		if(temp==NULL)
			cout<<"list is empty";
		else
		{
			while(temp!=NULL)
			{
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
	}
};	
int main()
{
	int l;
 	linkedlist a;
 	cout<<"enter size:";cin>>l;
 	for(int i=0;i<l;++i)
 	{
 		int temp;cin>>temp;
 		a.insert(i+1,temp);
 	}
 	int n;
 	cin>>n;
 	node *first=a.gethead()->next,*second=a.gethead();
 	for(int i=0;i<n;++i)
 	{
 		first=first->next;
 	}
 	while(first!=NULL)
 	{
 		first=first->next;
 		second=second->next;
 	}
 	second->next=second->next->next;
 	a.display();
}