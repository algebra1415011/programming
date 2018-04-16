#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll color[1000001];
vector<ll> v[1000001];
bool visited[1000001];
vector<ll> colorv[1000001];
 ll k;
 map<ll,ll> mp;
void dfs(ll src)
{
	visited[src]=true;
	if(colorv[color[src-1]].size()<k)
	{
	    mp[src]=-1;
	}
	else
	{
		// cout<<colorv[color[src-1]].size()-k<<"k"<<endl;
	    mp[src]=colorv[color[src-1]][colorv[color[src-1]].size()-k];
	}
	colorv[color[src-1]].push_back(src);
	for(ll i=0;i<v[src].size();i++)
	{
		if(!visited[v[src][i]])
			dfs(v[src][i]);
	}
	colorv[color[src-1]].pop_back();

 
}
 
int main()
{
 
    cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0);
	ll n,a,b;
	cin>>n>>k;
    
 
	for(ll i=0;i<n;i++)
	{
		cin>>color[i];
 
	}
	for(ll i=0;i<n-1;i++)
	{
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	dfs(1);
	for(ll i=1;i<=n;i++)
	{
		cout<<mp[i]<<" ";
       
	}
	cout<<endl;
 
	return 0;
}