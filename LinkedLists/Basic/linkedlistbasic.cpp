#include<iostream>
using namespace std;


class node
{
	
public:
	static int size;
	int data;
	node* next;
};
int node::size=0;
class linkedlist
{
	node *head;
public:
	linkedlist()
	{
		head=NULL;
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
			temp->size++;
			return;
		}
		if(pos>temp->size+1)
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
		temp->size++;
	}
	void del(int pos)
	{
		node* temp,*i;
		temp=new node;
		i=head;
		if(pos==1)
		{
			head=head->next;
			temp->size--;
			return;
		}
		if(pos>temp->size)
		{
		   cout<<"wrong position";
			return;	
		}
		--pos;
		while(--pos)
		{
			i=i->next;
		}
		temp=i->next;
		i->next=temp->next;
		delete temp;
		temp->size--;
	}
	// void ireverse()
	// {
	// 	node *i,*j,*k;
	// 	if(head==NULL)
	// 	{
	// 		cout<<"list is empty";
	// 		return;
	// 	}
	// 	if(head->next=NULL)
	// 	{
			
	// 		return;
	// 	}
	// 	i=head;
	// 	j=head->next;
	// 	while(j!=NULL)
	// 	{
	// 		k=j->next;
	// 		j->next=i;
	// 		if(i->next==j)
	// 			i->next=NULL;
	// 		i=j;
	// 		j=k;
	// 	}
	// 	head=i;
	// 	if(head->next==NULL)
	// 	{
	// 		cout<<"@";
	// 	}
	// }
	void rreverse(node *i,node*j)
	{
		if(j==NULL)
		{
			head=i;
			return;
		}
		rreverse(i->next,j->next);
		j->next=i;
		i->next=NULL;
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
	linkedlist l1;char ch;
	do{
		cout<<"1.insert\n2.delete\n3.display\n4.reverse\n";
		int a;
		cout<<"choice:";
		cin>>a;
		int pos;
		switch(a)
		{
			case 1:cout<<"position:";
			       cin>>pos;int value;cout<<"value:";cin>>value;
			       l1.insert(pos,value);
			       break;
			case 2:cout<<"position:";
			       cin>>pos;
			       l1.del(pos);      
			       break; 
			case 3:l1.display();break;
			case 4:l1.rreverse(l1.gethead(),l1.gethead()->next);break;
		}
		
		cout<<"continue?? :";cin>>ch;

	}while(ch=='y');
}