#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pb push_back
#define mp make_pair
void bellmanFord(int src,vector<vector<pair<int,int> > > &g)
{
    vector<int> dist(g.size(),INT_MAX);
    dist[src]=0;
    for(int i=0;i<g.size();++i)
    {
        for(int v=0;v<g.size();++v)
            for(int u=0;u<g[v].size();++u)
            {
                if(dist[g[v][u].f]>dist[v]+g[v][u].s)
                {
                   dist[g[v][u].f]=dist[v]+g[v][u].s ;
                }
            }
    }
    for(int v=0;v<g.size();++v)
        for(int u=0;u<g[v].size();++u)
        {
            if(dist[g[v][u].f]>dist[v]+g[v][u].s)
            {
               cout<<"negative cycle"<<endl;
               return;
            }
        }
    for(int i=0;i<dist.size();++i)
    {
        cout<<dist[i]<<" ";
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
    int src;
    cin>>src;
    bellmanFord(src,graph);
}