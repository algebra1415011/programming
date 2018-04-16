#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
ll arr[100010];
ll k,n;
ll mini=1e18;
ll dp[1000][1000];
ll solve(ll i,ll j,ll cnt)
{
	if(i>n or j<0 or i>=j)
		return 1e18;
	// cout<<i<<" "<<j<<endl;
	if(dp[i][j])
		return dp[i][j];
	if((arr[j]-arr[i])>k)
	{
		ll ans=solve(i+1,j,cnt+1);

		ans=min(ans,solve(i,j-1,cnt+1));
		dp[i][j]=ans;
		return ans;
	}
	else
	{
		dp[i][j]=cnt;
		return dp[i][j];
	}
	
}
int main()
{

	ios_base::sync_with_stdio(0);
	
	cin>>n>>k;
	if(n==1)
	{
		cout<<0<<endl;
		return 0;
	}

	
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	cout<<solve(0,n-1,0)<<endl;
	



	return 0;

}