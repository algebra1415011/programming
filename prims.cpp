#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<pair<ll,ll> > graph[1000010];
ll visited[1000010]; 
ll minimumcost=0;
void prims_baba(ll source)
{
	priority_queue<pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll > > > q;
	q.push(make_pair(0,source));
	while(!q.empty())
	{
		ll current=q.top().second;
		// cout<<current<<" ";
		ll w=q.top().first;
		q.pop();
		if(visited[current])
				continue;
		minimumcost+=w;
		//cout<<current<<" ";
		visited[current]=1;
		for(ll i=0;i<graph[current].size();i++)
		{
			if(!visited[graph[current][i].first])
				q.push(make_pair(graph[current][i].second,graph[current][i].first));
		}	

	}

}

int main()
{
	ll edges,vertex,x,y,w;
	cin>>vertex>>edges;
	for(ll i=0;i<edges;i++)
	{
		cin>>x>>y>>w;
		graph[x].push_back(make_pair(y,w));
		graph[y].push_back(make_pair(x,w));
	}
	prims_baba(1);
	cout<<minimumcost<<endl;

}