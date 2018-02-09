//merge 2 sorted lists
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
//int linkedlist::size=0;
linkedlist merge(linkedlist l1,linkedlist l2)
{
	linkedlist l3;
	node *i,*j;
	i=l1.gethead();
	j=l2.gethead();
	while(i!=NULL && j!=NULL)
	{
		if(i->data <= j->data )
			{l3.insert(l3.size+1,i->data);i=i->next;}
		else
			{l3.insert(l3.size+1,j->data);j=j->next;}
	}
	while(i!=NULL)
	{
		l3.insert(l3.size+1,i->data);i=i->next;
	}
	while(j!=NULL)
	{
		l3.insert(l3.size+1,j->data);j=j->next;
	}
	return l3;
}
int main()
{
	linkedlist l1,l2;
	l1.insert(1,2);
	l1.insert(2,7);
	l1.insert(3,9);
	l1.insert(4,17);
	l1.insert(5,23);

	l2.insert(1,1);
	l2.insert(2,5);
	l2.insert(3,20);

	linkedlist l3=merge(l1,l2);

	l3.display();
}