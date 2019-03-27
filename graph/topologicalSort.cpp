#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
void dfs(int i,vector<int> &visited,stack<int> &s,vector<vector<int> > &g)
{
	visited[i]=1;
	for(int j=0;j<g[i].size();++j)
		if(visited[g[i][j]]==0)
			dfs(g[i][j],visited,s,g);
	s.push(i);	
}
void topologicalSort(vector<vector<int> > &g)
{
	vector<int> visited(6,0);
	stack<int> s;
	for(int i=0;i<6;++i)
	{
		if(visited[i]==0)
		{
			dfs(i,visited,s,g);
		}
	} 
	while(s.size())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}
int main()
{
	vector<vector<int> > graph(6);
	graph[0].push_back(1);
    graph[0].push_back(3);
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(3);
    graph[2].push_back(5);
    graph[2].push_back(4);
    graph[3].push_back(4);
    graph[3].push_back(5);
    graph[4].push_back(5);
    topologicalSort(graph);
}