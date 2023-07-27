#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mx=1e3+5;
vector<ll>par(mx,1);
vector<ll>siz(mx,1);
vector<bool>vis(mx,false);

vector< pair<ll,ll> >mst_edges;


ll parent(ll u)
{
	if(par[u]==u)
		return u;

	return par[u]=parent(par[u]);
}

bool make(ll u,ll v)
{
	u=parent(u),v=parent(v);
	if(u==v)
		return false;
	if(siz[u]>siz[v])
		swap(u,v);
	par[u]=v;
	siz[v]+=siz[u];

	return true;
}

void kruskal_Algo()
{
    ll n,m,i,w,u,v,mst_w=0;
    cin>>n>>m;

    for(i=0;i<=n;i++)
		par[i]=i;

	set< pair<ll, pair<ll,ll> > >s;

    for(i=0;i<m;i++)
    {
    	cin>>u>>v>>w;
    	s.insert({w,{u,v}});
    }

   while(s.size())
   {
   	 auto ele=*(s.begin());
   	 w=ele.first;
   	 u=ele.second.first;
   	 v=ele.second.second;
   	 s.erase(s.begin());

   	 if(make(u,v))
   	 {
   	 	mst_edges.push_back({u,v});
   	 	mst_w+=w;
   	 }

   }
    
    cout<<mst_w<<"\n";
}

int main()
{
	
   kruskal_Algo();

}