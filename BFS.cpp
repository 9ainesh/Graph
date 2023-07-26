#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
const int mx=1e3+6;

vector<int>graph[mx];
int height[mx];
int depth[mx];
bool vis[mx];
int subtree_sum[mx];
int parent[mx];
int lvl[mx];

vector< pair<int,int> >wtGraph[mx];

void bfs(ll src)
{
	queue<ll>q;
	q.push(src);
	lvl[src]=1;

	//  level printing

	while(q.size())
	{
		ll cnt=q.size();
		while(cnt--)
		{
			ll node=q.front();
			vis[node]=true;
			q.pop();
			cout<<node<<" ";
			for(auto ele:graph[node])
			{
				if(vis[ele])
					continue;
				q.push(ele);
				lvl[ele]=lvl[node]+1;
			}
		}
		cout<<"\n";
	}
}

void BFS_0_1(int src)
{
        deque< ll >q;
        q.push_front({src,0});
        while(q.size())
        {
        
        	ll node=ele.first;
        	q.pop_front();
        
        	for(auto child:wtGraph[node])
        	{
        		ll childnode=child.first;
        		ll childwt=child.second;
        		if(lvl[node]+childwt<lvl[childnode])
        		{
        			lvl[childnode]=lvl[node]+childwt
        			if(childwt==0)
        			q.push_front(childnode);
        		   else
        		   	q.push_back(childnode);
        		}


        	}
        }
}






int main()
{
	ll n,m,i,j,w;
	cin>>n>>m;
	memset(vis,false,sizeof(vis));
	memset(lvl,mx,sizeof(lvl));

	// while(m--)
	// {
	// 	cin>>i>>j;
	// 	graph[i].push_back(j);
	// 	graph[j].push_back(i);
	// }

	// for(i=1;i<=n;i++)
	// {
	// 	if(vis[i])
	// 	 continue;
	// 	bfs(i);
	// }

	while(m--)
	{
		cin>>i>>j>>w;
		wtGraph[i].push_back({j,w});
		wtGraph[j].push_back({i,w});
	}

}







