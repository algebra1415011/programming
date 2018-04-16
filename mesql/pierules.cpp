#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[100];
ll dp[100][100];
ll n;
ll solve(ll in,ll decide)
{
	if(in==n)
		return 0;
	if(dp[in][decide]!=-1)
		return dp[in][decide];

	ll ans=0;
	if(decide==1)
		ans=max(solve(in+1,decide),solve(in+1,decide^1)+arr[in]);
	else
		ans=min(solve(in+1,decide)+arr[in],solve(in+1,decide^1));
	dp[in][decide]=ans;
	return ans;

}

int main()
{
	
	cin>>n;
	memset(dp,-1,sizeof(dp));
	ll sum=0;
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	cout<<sum-solve(0,1)<<" "<<solve(0,1)<<endl;

}