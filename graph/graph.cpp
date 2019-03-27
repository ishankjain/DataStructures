#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pb push_back
#define mp make_pair

int main()
{
	ll v,e;
	cin>>v>>e;
	vector<vector<int> > graph(v);
	for(int i=0;i<e;++i)
	{
		ll src,dest;
		cin>>src>>dest;
		graph[src].pb(dest);
		// graph[dest].pb(src);
	}
}