#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
ll dp[1000010];
ll arr[1000010];
ll n;

ll solve(ll arr[],ll i)
{
	if(i==n)
		return INT_MIN;
	if(dp[i]!=(-1e4-1))
		return dp[i];

	ll ans=arr[i]+solve(arr,i+1);
	ll res=solve(arr,i+1);
	if(ans%2!=0 and res%2!=0)	
	{
		dp[i]=max(ans,res);
	}
	else if(ans%2!=0)
	{
		dp[i]=ans;
	}
	else if(res%2!=0)
	{
		dp[i]=res;
	}
	cout<<dp[i]<<" ";
	return dp[i];

	
}


int main()
{

	
	cin>>n;
	memset(dp,-1e4-1,sizeof(dp));
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	cout<<solve(arr,0)<<endl;
}