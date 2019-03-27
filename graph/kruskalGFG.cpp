#include<bits/stdc++.h>
using namespace std;



struct Graph
{
    int V, E;
    vector< pair<int, pair<int, int> > > edges;

    Graph(int Ve, int Ee)
    {
        V = Ve;
        E = Ee;
    }

    void AddEdge(int u, int v, int w)
    {
        edges.push_back({w, {u, v}});
    }

    int kruskalMST();
};

struct DisjointSets
{
    int *parent, *Rank;
    int n;

    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n+1];
        Rank = new int[n+1];

     for (int i = 0; i <= n; i++)
        {
            Rank[i] = 0;

            parent[i] = i;
        }
    }

    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void merge(int x, int y)
    {
        x = find(x), y = find(y);

       if (Rank[x] > Rank[y])
            parent[y] = x;
        else
            parent[x] = y;

        if (Rank[x] == Rank[y])
            Rank[y]++;
    }
};


int Graph::kruskalMST()
{
    int W = 0;
    sort(edges.begin(), edges.end());
    DisjointSets Ds(V);

    vector< pair<int, pair<int, int> > >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = Ds.find(u);
        int set_v = Ds.find(v);
        if (set_u != set_v)
        {
            cout << u << " - " << v << endl;

            W += it->first;
            Ds.merge(set_u, set_v);
        }
    }

    return W;
}

int main()
{
    int V ,E;
    cin>>V>>E;
    Graph G(V, E);
    int U,v,w;
    for(int i=0;i<E;i++)
       {
        cin>>U>>v>>w;
        G.AddEdge(U,v,w);
       }

    cout << "EDGES OF MST ARE \n";
    int W = G.kruskalMST();

    cout << "\nWEIGHT OF MST IS " << W;

    return 0;
}