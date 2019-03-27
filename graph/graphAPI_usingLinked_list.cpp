
//Graph api
//adjacency list using linked list

#include<bits/stdc++.h>
using namespace std;
struct nodeList;
struct edgeList;
struct nodeList{
	char name;
	nodeList* next;
	edgeList* adj;
};
struct edgeList{
	char src,dest;
	int weight;
	edgeList* link;
};
class Graph{
	nodeList* start;
public:
	Graph()
	{
		start=NULL;
	}
	bool find(char a);
	void insertNode(char a);
	void insertEdge(char a,char b,int wt);
	void delEdge(char a, char b);
};
bool Graph::find(char a)
{
	nodeList* ptr=start;
	while(ptr!=NULL)
	{
		if(ptr->name==a)
			return true;
		ptr=ptr->next;
	}
	return false;
}
void Graph::insertNode(char a)    //insertion in beginning of nodeList
{
	if(find(a))
	{
		return;                    //node already in the Graph
	}	
	nodeList* temp=new nodeList;
	temp->name=a;
	temp->next=NULL;
	temp->adj=NULL;
	if(start== NULL)
	{
		start=temp;
		return;
	}
	temp->next=start;
	start=temp;
}
void Graph::insertEdge(char a,char b,int wt)
{
	if(!find(a))
	{
		insertNode(a);
	}
	if(!find(b))
	{
		insertNode(b);
	}
	nodeList* ptr=start;
	edgeList* temp=new edgeList;
	temp->link==NULL;
	temp->weight=wt;
	int flag=0;
	while(ptr!=NULL)
	{
		if(ptr->name==a)
		{
			temp->src=a;
			temp->dest=b;
			if(ptr->adj==NULL)
			{
				ptr->adj=temp;
				break;
			}
			temp->link=ptr->adj;
			ptr->adj=temp;
			flag++;
		}
		if(ptr->name==b)
		{
			temp->src=b;
			temp->dest=a;
			if(ptr->adj==NULL)
			{
				ptr->adj=temp;
				break;
			}
			temp->link=ptr->adj;
			ptr->adj=temp;
			flag++;
		}
		if(flag==2)
			break;
		ptr=ptr->next;
	}
}
void Graph:: delEdge(char a,char b)
{
	if(!find(a) || !find(b))
	{
		return;                       // no such nodes exist in th Graph
	}
	nodeList* ptr=start;
	int flaga=0,flagb=0;
	while(ptr!=NULL)
	{
		if(ptr->name==a)
		{
			edgeList* temp=new edgeList; 
			edgeList* ptr2=ptr->adj;
			if(ptr2==NULL)
			{
				break;                   //no such edge exist
			}
			if(ptr2->link==NULL && ptr2->dest==b)
			{
				flaga++;
				temp=ptr2;
				ptr->adj=NULL;
				delete temp;
			}
			while(ptr2->link!=NULL)
			{
				if(ptr2->link->dest==b)
				{
					flaga++;
					temp=ptr2->link;
					ptr2->link=temp->link;
					delete temp;
					break;
				}
			}
			if(flaga==0)
				break;                //no such edge exist
		}
		if(ptr->name==b)
		{
			edgeList* temp=new edgeList; 
			edgeList* ptr2=ptr->adj;
			if(ptr2==NULL)
			{
				break;                   //no such edge exist
			}
			if(ptr2->link==NULL && ptr2->dest==a)
			{
				flagb++;
				temp=ptr2;
				ptr->adj=NULL;
				delete temp;
			}
			while(ptr2->link!=NULL)
			{
				if(ptr2->link->dest==b)
				{
					flagb++;
					temp=ptr2->link;
					ptr2->link=temp->link;
					delete temp;
					break;
				}
			}
			if(flagb==0)
				break;                   //no such edge exist
		}
		if(flaga==1 && flagb==1)
			break;
		ptr=ptr->next;
	}
}
