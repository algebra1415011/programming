#include <bits/stdc++.h>
#define ll long long int
#define inf -4e18
using namespace std;
ll dp[100005][4];
ll n;
ll solve(ll arr[],ll brr[],ll i,ll j)
{
	
	if(i==n) return 0;
	if(j==4) return 0; 
	if(dp[i][j]!=inf)
		return dp[i][j];
	ll ans = -1e18*4;
	ans=arr[i]*brr[j]+solve(arr,brr,i,j+1);
	ans=max(ans,solve(arr,brr,i+1,j));
	dp[i][j]=ans;
	// cout<<i<<" "<<j<<" "<<ans<<endl;
	return dp[i][j]; 
}


int main()
{
		
	
	
	ll brr[4];
	for(ll i=0;i<4;i++)
		cin>>brr[i];
	n=brr[0];
	ll arr[n];
	memset(dp,inf,sizeof(dp));
	for(ll i=0;i<brr[0];i++)
	{
		cin>>arr[i];
	}
	cout<<solve(arr,brr,0,1)<<endl;

}