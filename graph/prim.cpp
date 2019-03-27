#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pb push_back
#define mp make_pair
void prim(vector<vector<pair<int,int> > > &g)
{
    priority_queue <pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > pq;
    vector<int> visited(g.size());
    for(int i=0;i<g[0].size();++i)
    {
        pq.push(mp(g[0][i].s,mp(0,g[0][i].f)));
    }
    visited[0]=1;
    while(!pq.empty())
    {
        int src=pq.top().s.f;
        int dest=pq.top().s.s;
        int wt=pq.top().f;
        pq.pop();
        if(visited[dest]==1)
        {
            continue;
        }
        visited[dest]=1;
        cout<<src<<" "<<dest<<" "<<wt<<endl;
        for(int i=0;i<g[dest].size();++i)
        {
            pq.push(mp(g[dest][i].s,mp(dest,g[dest][i].f)));
        }
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
        graph[dest].pb(mp(src,wt));
    }
    prim(graph);
}