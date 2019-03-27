#include<bits/stdc++.h>
using namespace std;

void dfs(int i,vector<int> &visited,vector<vector<int> > &graph)
{
	visited[i]=1;
	for(int j=0;j<graph[i].size();++j)
		if(visited[graph[i][j]]==0)
			dfs(graph[i][j],visited,graph);
		
}

void bfs(int i,vector<vector<int> > &graph)
{
	vector<int> visited(n,0);
	queue<int> q;
	q.push(i);
	visited[i]=1;
	while(q.size())
	{
		int temp=q.front();
		for(int j=0;j<graph[temp].size();++j)
		{
			if(visited[graph[temp][j]]==0)
			{
				visited[graph[temp][j]]=1;
				q.push(graph[temp][j]);
			}
		}
		q.pop();
	}
}