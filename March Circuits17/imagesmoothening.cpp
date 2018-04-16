#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll brr[101][101];
int main()
{
	ll n,m,k;
	cin>>n>>m;
	ll arr[n][n];
	map<pair<ll,ll>,ll> mp;
	for(ll i=-m;i<=m;i++)
		for(ll j=-m;j<=m;j++)
		{
			cin>>k;
			mp[make_pair(i,j)]=k;
		}
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			cin>>arr[i][j];

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)			
			for(ll p=-m;p<=m;p++)
				for(ll q=-m;q<=m;q++)
							if(i+p>=0 && i+p<n && j+q>=0 && j+q<n)
									brr[i][j]+=arr[i+p][j+q]*mp[make_pair(p,q)];
							
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
			cout<<brr[i][j]<<" ";
		cout<<endl;	
	}	

}