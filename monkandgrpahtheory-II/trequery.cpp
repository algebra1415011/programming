#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
vector<ll> v[1000010]; 
vector<ll> vr[1000010];
ll visit[1000010];
void dfs1(ll s)
{
	visit[s]=1;
	for(ll i=0;i<v[s].size();i++)
	{
		if(!visit[v[s][i]])
			dfs1(v[s][i]);
	}
}
void dfs2(ll s)
{
	visit[s]=1;
	for(ll i=0;i<vr[s].size();i++)
	{
		if(!visit[vr[s][i]])
			dfs2(vr[s][i]);
	}
}


int main()
{
	ll n,a,b,m;
	cin>>n>>m;
	for(ll i=0;i<m;i++)
	{
		cin>>a>>b;
		v[a].push_back(b);
		vr[b].push_back(a);
	}
	memset(visit,0,sizeof(visit));
	ll c=0;
	for(ll i=1;i<=n;i++)
	{
		if(v[i].size()==0)
		{
			c++;
			
		}
	}
	cout<<c<<endl;
	memset(visit,0,sizeof(visit));
	ll c1=0;
	for(ll i=1;i<=n;i++)
	{
		if(vr[i].size()==0)
		{
			c1++;
			dfs2(i);
		}
	}
	cout<<c1<<endl;
	cout<<max(c1,c)<<endl;



}
