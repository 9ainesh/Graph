// to find the shortest distance of all node from a particular node
// will work on directed as well as undirected 
// will work on cyclic as well as acyclic
// practically will not work on negative weight cycles
// Bcz it will stuck in infinite loop

// But the following code id written in such manner that 
// effect of negative cycle is avoided bcz I'm using vis
// if we remove vis , it will stuck in infinite
// if we mark element as visited it means, 
// its shortest distance is finalized


#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mx=1e3+5;

vector<ll>dist(mx,mx);
vector< pair<ll,ll>  >graph[mx];
vector< bool >vis(mx,false);


void dijsktra(ll src)
{
    dist[src]=0;
    set< pair<ll,ll> >s;
    s.insert({0,src});
    while(s.size())
    {
    	auto ele=*(s.begin());
    	s.erase(s.begin());

    	ll w=ele.first;
    	ll node=ele.secod;

    	if(vis[node])
    		continue;

    	vis[node]=true;

    	for(auto chld:graph[node])
    	{
    		ll curnode=chld.first;
    		ll wt=chld.second;
    		ll totWt=w+wt;
    		
    		if(totWt<dist[curnode] and vis[curnode]==false)
    		{
    			dist[curnode]=totWt;
    			s.insert({totWt,curnode});
    		}
    	}
    }

    for(i=1;i<=n;i++)
    	cout<<dist[i]<<" ";

}

int main()
{
	ll i,n,m,u,v,w;
    cin>>n>>m;
    while(m--)
    {
    	cin>>u>>v>>w;
    	graph[u].push_back({v,w});
    	graph[v].push_back({u,w});
    }
    dijsktra(1);
}