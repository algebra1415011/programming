#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
ll n,m;
ll mat[20][20];
ll mod=1e9+7;
ll dp[(1<<20)][20];
ll rec(ll row,ll bit)
{
	if(row==n || bit==(1<<20))
	{
	    return 1; 
	}
	ll ans=0;
	if(dp[bit][row]!=-1)
	    return dp[bit][row];
	else
	{
	    for(ll i=0;i<n;i++)
	    {
	        if(!(bit&(1<<i)))
	        {
	            ll temp=(mat[row][i]*(rec(row+1,bit|(1<<i))))%mod;
	            ans=(ans+temp)%mod;
	        }
	    }
	}
	dp[bit][row]=ans;
	return ans;
	
}
int main()
{
	
	cin>>n>>m;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++)
			{
				ll ak;
				cin>>ak;
				mat[i][ak]++;
			}
			
	
	memset(dp,-1,sizeof(dp));
	cout<<rec(0,0)%mod<<endl;
	

	
	
}