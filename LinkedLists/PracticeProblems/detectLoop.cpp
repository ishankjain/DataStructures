//detect loop in linked list

#include<iostream>
using namespace std;
class node
{
	
public:
	int data;
	node* next;
};
node *newNode(int key)
{
    node *temp = new node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
void detectLoop(node *head)
{
	node *slow=head,*fast=head;
	if(head==NULL || head->next==NULL)
	{
		cout<<"no loop";
		return;
	}
	slow=slow->next;
	fast=fast->next->next;
	while(fast && fast->next)
	{
		if(slow==fast)
		{
			break;
		}
		slow=slow->next;
		fast=fast->next->next;
	}
	if(slow==fast)
	{
		slow=head;
		int ctr=0;
		while(slow!=fast)
		{
			ctr++;
			slow=slow->next;
			fast=fast->next;
		}
		cout<<"found at node "<<ctr+1;
		
	}
	else
	{
		cout<<"loop not found";
		return;
	}
}
int main()
{
	node *head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
    head->next->next->next->next->next = head->next->next;

    detectLoop(head);

}