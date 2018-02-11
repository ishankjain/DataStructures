// https://leetcode.com/problems/add-two-numbers-ii/description/

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
int add(node* i,node* j,linkedlist &res)
{
	if(i==NULL && j==NULL)
		return 0;
	int c=add(i->next,j->next,res);
	int s=(c+i->data+j->data)%10;
	c=(c+i->data+j->data)/10;
	res.insert(1,s);
	return c;
}
int add2(node* i,node* j,int carry,linkedlist &res)
{
	if(i==j)
		return carry;
	int c=add2(i->next,j,carry,res);
	int s=(c+i->data)%10;
	c=(c+i->data)/10;
	res.insert(1,s);
	return c;
}
 int main()
 {
 	int n;
 	linkedlist a,b,res;
 	cout<<"enter no. of digits in first number:";cin>>n;
 	for(int i=0;i<n;++i)
 	{
 		int temp;cin>>temp;
 		a.insert(i+1,temp);
 	}
 	cout<<"enter no. of digits in second number:";cin>>n;
 	for(int i=0;i<n;++i)
 	{
 		int temp;cin>>temp;
 		b.insert(i+1,temp);
 	}
 	int carry,x;
 	if(a.size>=b.size)
 	{
 		node* one=a.gethead();
 		for(int i=0;i<a.size-b.size;++i)
 		{
 			one=one->next;
 		}
 		carry=add(one,b.gethead(),res);
 		x=add2(a.gethead(),one,carry,res);
 	}
 	else
 	{
 	    node* two=b.gethead();
 		for(int i=0;i<b.size-a.size;++i)
 		{
 			two=two->next;
 		}
 		carry=add(a.gethead(),two,res);	
 		x=add2(b.gethead(),two,carry,res);
 	}
 	if(x==1)
 	{
 		res.insert(1,x);
 	}
 	res.display();
 }