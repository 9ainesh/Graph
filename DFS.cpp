#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
const int mx=1e3+6;

vector<int>graph[mx];
int height[mx];
int depth[mx];
bool vis[mx];

vector< vector<int> >compo;
vector<int>tmp;



void dfs(int node)
{
	vis[node]=true;
	//cout<<node<<" ";
	tmp.push_back(node);
	for(auto ele:graph[node])
	{
		if(vis[ele])
			continue;

		depth[ele]=depth[node]+1;
		dfs(ele);
		height[node]=max(height[ele]+1,height[node]);
	}
    
}

bool is_cycle(int node,int par)
{
	vis[node]=true;

	for(auto ele:graph[node])
	{
		if(vis[ele])
		{
			if(ele!=par)
				return true;
			continue;
		}

		if(is_cycle(ele,node))
			return true;

	}
	return false;
}


int main()
{
	ll n,m,i,j;
	cin>>n>>m;
	memset(vis,false,sizeof(vis));
	while(m--)
	{
		cin>>i>>j;
		graph[i].push_back(j);
		graph[j].push_back(i);
	}

	for(int i=1;i<=n;i++)
	{
		if(vis[i])
			continue;
		// tmp.clear();
		// dfs(i);
		// compo.push_back(tmp);
		if(is_cycle(i,-1))
		{
			cout<<"is_cycle"<<"\n";
			break;
		}
	}

	// for(i=1;i<=n;i++)
	// {
	// 	cout<<height[i]<<" "<<depth[i]<<"\n";
	// }

	// cout<<"\ncompo: "<<compo.size()<<"\n";
	// for(auto ele:compo)
	// {
	// 	for(auto el:ele)
	// 	{
	// 		cout<<el<<" ";
	// 	}
	// 	cout<<"\n";
	// }

}