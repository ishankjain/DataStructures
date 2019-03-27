//ford fulkerson algorithm

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
bool bfs(vector<vector<pair<ll,ll> > > r,ll s,ll t,vector<pair<ll,ll> > &par)
{
    vector<bool> visited(6);
    queue <ll> q;
    q.push(s);
    visited[s] = true;
    par[s].f = -1;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
 
        for (ll v=0; v<r[u].size(); v++)
        {
            if (visited[r[u][v].f]==false && r[u][v].s > 0)
            {
                q.push(r[u][v].f);
                par[r[u][v].f].f = u;
                par[r[u][v].f].s=r[u][v].s;
                visited[r[u][v].f] = true;
            }
        }
    }
 
    // If we reached sink in BFS starting from source, then return
    // true, else false
    return (visited[t] == true);
}
ll maxflow(vector<vector<pair<ll,ll> > > r,ll s,ll t)  
{
	ll flow=0;
	vector<pair<ll,ll> > par(6);
	while(bfs(r,s,t,par))
	{
		ll path_flow=LLONG_MAX;
		for (ll v=t; v!=s; v=par[v].f)
        {
            path_flow = min(path_flow,par[v].s);
        }
        for (ll v=t; v != s; v=par[v].f)
        {
            ll u = par[v].f;
            for(ll i=0;i<r[u].size();++i)
            {
            	if(r[u][i].f==v)
            	{
            		r[u][i].s-=path_flow;
            		break;
            	}
            }
        }
        flow+=path_flow;
	}
	return flow;
}
int main()
{
	vector<vector<pair<ll,ll> > > a(6);
	a[0].push_back(make_pair(1,16));
	a[0].push_back(make_pair(2,13));
	a[1].push_back(make_pair(2,10));
	a[1].push_back(make_pair(3,12));
	a[2].push_back(make_pair(1,4));
	a[2].push_back(make_pair(4,14));
	a[3].push_back(make_pair(2,9));
	a[3].push_back(make_pair(5,20));
	a[4].push_back(make_pair(3,7));
	a[4].push_back(make_pair(5,4));
	cout<<maxflow(a,0,5);

}