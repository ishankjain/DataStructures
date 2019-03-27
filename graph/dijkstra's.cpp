#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pb push_back
#define mp make_pair 
void djikstra(int src,vector<vector<pair<int,int> > > &g)
{
    priority_queue <pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    vector<int> dist(g.size(),INT_MAX);
    dist[src]=0;
    vector<bool> final(g.size(),false);
    pq.push(mp(dist[src],src));
    int ctr=0;
    while(ctr!=dist.size())
    {
        int temp=pq.top().s;
        pq.pop();
        if(final[temp])
            continue;
        ctr++;
        final[temp]=true;
        for(int i=0;i<g[temp].size();++i)
        {
            if(dist[g[temp][i].f]>dist[temp]+g[temp][i].s)
            {
                dist[g[temp][i].f]=dist[temp]+g[temp][i].s;
                pq.push(mp(dist[g[temp][i].f],g[temp][i].f));
            }
        }
    }
    for(int i=0;i<g.size();++i)
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
    djikstra(src,graph);
}