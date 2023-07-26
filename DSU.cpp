// combine them 
// if they are already in the same group skip
// can use to detect the cycle
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mx=1e3+5;
vector<ll>par(mx,1);
vector<ll>siz(mx,1);

ll parent(ll u)
{
	if(par[u]==u)
		return u;
	return par[u]=parent(par[u]);
}

bool make(ll u,ll v)
{
    u=parent(u),v=parent(v);

    // both are already in the same group
    // so if we join them, it will create a cycle

    if(u==v)
    	return true;

    if(siz[u]>siz[v])
    	swap(u,v);

    par[u]=v;
    siz[v]+=siz[u];

    return false;
}

int main()
{
	ll q,i,cnt=0;
	cin>>q;

	for(i=1;i<=mx;i++)
		par[i]=i;

	while(q--)
	{
		// combine u  and v
		cin>>u>>v;
		if(make(u,v))
			cout<<"Graph has cycle\n";

	}

	// to find the number of connected components
	// cnt par[u] == u 
   
}