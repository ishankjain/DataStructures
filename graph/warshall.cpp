#include<bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int> > &graph)
{
	vector<vector> > shortest_path;
	shortest_path=graph;
	for(int i=0;i<graph.size();++i)            
	{
		for(int j=0;j<graph.size();++j)
		{
			if(graph[i][j]==100000)
				shortest_path[i][j]=INT_MAX;
		}
	}
	for(int k=0;k<n;++k)              
	{
		for(int i=0;i<n;++j)
		{
			for(int j=0;j<n;++j)
			{
				shortest_path[i][j]=min(shortest_path[i][j],shortest_path[i][k]+shortest_path[k][j]);
			}
		}
	}
}

int main()
{
	ll v;        //no. of vertices
	cin>>v;
	vector<vector<int> > graph(v,vector<int>(v));              // graph in adjacency matrix form
	cout<<"enter the graph in adjacency matrix form(enter 100000 if there is no edge between the vertices):"<<endl;
	for(int i=0;i<v;++i)
	{
		for(int j=0;j<v;++j)
		{
			cin>>graph[i][j];
		}
	}
	floydWarshall(graph);        //function to calculate all pair shortest path 
}