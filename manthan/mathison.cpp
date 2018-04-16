#include <bits/stdc++.h>
#define ll long long int
using namespace std ;
int main()
{

	ll n,k,m;
	cin>>n>>k>>m;
	ll p=k;
	ll arr[m][n];
	vector<pair<ll,pair<ll,ll> > > v[10000],temp;
	for(ll i=0;i<m;i++)
	{
		for(ll j=0;j<n;j++)
			{
				cin>>arr[i][j];
				v[i].push_back(make_pair(arr[i][j],make_pair(i+1,j+1)));
				
			}
			
	}
	for(ll i=0;i<m;i++)
		sort(v[i].begin(),v[i].end());

	for(ll i=1;i<m;i++)
	{
		if(v[i][0].second.second!=v[i-1][0].second.second)
			{
				temp.push_back(v[i][0]);
				temp.push_back(v[i-1][0]);
			}	
			else
			{
				temp.push_back(v[i][0]);
				temp.push_back(v[i-1][1]);
			}

	}
	map<ll,ll> mp;
	ll t=0;
	for(ll i=0;temp.size();i++)
	{
		if(!mp[temp[i].second.first])
			{
				cout<<temp[i].second.first<<" ";
				t++;
				if(t==p)
				exit(0);
			}
		if(!mp[temp[i].second.second])
			{	
					cout<<temp[i].second.second<<" ";t++;
				if(t==p)
				exit(0);
			}

	}
for(ll i=1;i<n;i++)
{
	if(!mp[i])
	{
		cout<<i<<" ";
		t++;
if(t==p)
	exit(0);
	}
}
	
	return 0;
}