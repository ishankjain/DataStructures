#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pb push_back
#define mp make_pair
int findset(int x,vector<int> &a)
{
    while(x!=a[x])
    {
        x=a[x];
    }
    return x;
}
void join(int x,int y,vector<int> &a)
{
    while(x!=a[x])
        x=a[x];
    while(y!=a[y])
        y=a[y];
    a[y]=x;
}
void kruskal(vector<vector<pair<int,int> > > &g)
{
    set <pair<int,pair<int,int> > > pq;
    for(int v=0;v<g.size();++v)
    {
        for(int u=0;u<g[v].size();++u)
        {
            pq.insert(mp(g[v][u].s,mp(v,g[v][u].f)));
        }
    }
    vector<int> a(g.size());
    for(int i=0;i<a.size();++i)
    {
        a[i]=i;
    }
    while(!pq.empty())
    {
        int wt=(*pq.begin()).f;
        int src=(*pq.begin()).s.f;
        int dest=(*pq.begin()).s.s;
        if(findset(src,a)!=findset(dest,a))
        {
            cout<<src<<" "<<dest<<" "<<wt<<endl;
            join(src,dest,a);
        }
        pq.erase(pq.begin());
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
    kruskal(graph);
}