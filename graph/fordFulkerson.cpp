#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pb push_back
#define mp make_pair 
void fordFulkerson(int src,int target,vector<vector<pair<int,int> > > g)
{
	int maxflow=0;
	vector<int> path;
	while(augmentedPath(src,target,g))
	{
		int i=0;
		while(path[i]!=i)
	}
}
int main()
{
    ll v,e;
    cin>>v>>e;
    vector<vector<pair<int,int> > > graph(v);
    for(int i=0;i<e;++i)
    {
        ll src,dest,wt;
        cin>>src>>dest>>wt;
        graph[src].pb(mp(dest,wt));
        // graph[dest].pb(mp(src,wt));
    }
    int src,target;
    cin>>src>>target;
    fordFulkerson(src,target,graph);
}