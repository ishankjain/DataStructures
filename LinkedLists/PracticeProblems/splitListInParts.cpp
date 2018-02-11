//https://leetcode.com/problems/split-linked-list-in-parts/description/

#include<iostream>
#include<vector>
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
	linkedlist l1;
	int n;cin>>n;
	for(int i=1;i<=n;++i)
	{
		l1.insert(i,i);
	}
	int k;
	cin>>k;
	int a,b;
	a=n/k;
	b=n%k;
	node* t=l1.gethead();
	vector<linkedlist> ans;
	for(int i=0;i<b;++i)
	{
		linkedlist temp;
		for(int j=0;j<a+1;++j)
		{
			temp.insert(j+1,t->data);
			t=t->next;
		}
		ans.push_back(temp);
	}
	for(int i=0;i<k-b;++i)
	{
		linkedlist temp;
		for(int j=0;j<a;++j)
		{
			temp.insert(j+1,t->data);
			t=t->next;
		}
		ans.push_back(temp);
	}
	for(int i=0;i<k;++i)
	{
		cout<<i+1<<":";
		ans[i].display();
		cout<<endl;
	}
}