#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
int main()
{
	ll n,k,m;
	cin>>n>>k>>m;
	string s[n+1];
	ll cost[n+1];
	map<string,ll> mp;
	for(ll i=1;i<=n;i++)
		{
			cin>>s[i];
			mp[s[i]]=i;

		}	
	for(ll i=1;i<=n;i++)
		cin>>cost[i];
	for(ll i=0;i<k;i++)
	{
		ll x,p;
		cin>>x;
		ll mini=1e18;
		vector<ll> v;
		for(ll j=0;j<x;j++)
		{
			cin>>p;
			v.push_back(p);
			mini=min(mini,cost[p]);
		}
		for(ll j=0;j<v.size();j++)
		{
			cost[v[j]]=mini;
		}
	}
	ll sum=0;
	string t;
	for(ll i=0;i<m;i++)
	{
		cin>>t;
		sum+=cost[mp[t]];
	}
	cout<<sum<<endl;
	return 0;
}