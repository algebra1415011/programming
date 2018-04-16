#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[1000001][19];
ll arr[1000001];
int main()
{
	ll n,q;
	cin>>n>>q;
	for(ll i=0;i<n;i++)
		cin>>arr[i];
	for(ll i=0;i<n;i++)
		dp[i][0]=i;
	
	for(ll j=1;(1<<j)<=n;j++)
	{
		for(ll i=0;i+((1<<j)-1)<n;i++)
		{
			if(arr[dp[i][j-1]]>=arr[dp[i+(1<<j)-1][j-1]])
				dp[i][j]=dp[i+(1<<j)-1][j-1];
			else
				dp[i][j]=dp[i][j-1];
		}
	}
	ll a,b;
	for(ll i=0;i<q;i++)
	{
		cin>>a>>b;
		ll c=log2(b-a+1);
		if(arr[dp[a][c]]<=arr[dp[b-(1<<c)+1][c]])
			cout<<arr[dp[a][c]];
		else
			cout<<arr[dp[b-(1<<c)+1][c]]<<endl;
	}



}