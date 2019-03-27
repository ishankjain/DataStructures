#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pb push_back
#define mp make_pair
void dfs(int i,vector<int> &visited,stack<int> &s,vector<vector<int> > &g)
{
	visited[i]=1;
	for(int j=0;j<g[i].size();++j)
		if(visited[g[i][j]]==0)
			dfs(g[i][j],visited,s,g);
	s.push(i);	
}
void topological(vector<vector<int> > &g,stack<int> &s)
{
	vector<int> visited(5,0);
	for(int i=0;i<5;++i)
	{
		if(visited[i]==0)
		{
			dfs(i,visited,s,g);
		}
	} 
}
void transpose(vector<vector<int> > &g,vector<vector<int> > &t)
{
	for(int i=0;i<g.size();++i)
	{
		for(int j=0;j<g[i].size();++j)
		{
			t[g[i][j]].pb(i);
		}
	}
}
void scc(int t,vector<vector<int> > &grapht,vector<int> &visited)
{
	cout<<t<<" ";
	visited[t]=1;
	for(int i=0;i<grapht[t].size();++i)
	{
		if(visited[grapht[t][i]]==0)
		{
			scc(grapht[t][i],grapht,visited);
		}
	}
}
int main()
{
	ll v,e;
	cin>>v>>e;
	vector<vector<int> > graph(v),grapht(v);
	for(int i=0;i<e;++i)
	{
		ll src,dest;
		cin>>src>>dest;
		graph[src].pb(dest);
		// graph[dest].pb(src);
	}
	stack<int> s,st;
	topological(graph,s);
	// st=s;
	// while(st.size())
	// {
	// 	cout<<st.top()<<" ";
	// 	st.pop();
	// }
	// cout<<endl;
	transpose(graph,grapht);
	vector<int> visited(v,0);
	while(s.size())
	{
		int t=s.top();
		s.pop();
		if(visited[t]==0)
		{
			scc(t,grapht,visited);
			cout<<endl;
		}
	}

}