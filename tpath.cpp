#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define inf 1e18
using namespace std;
ll check[1000010];
ll arr[1002][1002];
ll dp[1002][1002]; 
ll mat[1002][1002];

ll n,m;
ll c=0;
void dfs(ll i,ll j)
{
	cout<<i<<" "<<j<<endl;
	if(i==n and j==m)
	{
		return ;
	}
	else if(mat[i+1][j+1])

	{
		dfs(i+1,j+1);
	}
	else if(mat[i][j+1])
		dfs(i,j+1);
	else if(mat[i+1][j+1])
	{

	}
}


void sieve()
{
	for(ll i=2;i<=100000;i++)
	{
		if(!check[i])
		{
			//cout<<i<<" ";
			for(ll j=(2*i);j<=100000;j=j+i)
				check[j]=1;
		}
	}
}


int main()
{


	sieve();
	
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++)
			{
				cin>>arr[i][j];
				if(!check[arr[i][j]])
					mat[i][j]=1;
			}	

	dp[0][0]=1;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			if(!check[arr[i][j]])
				{
					dp[i][j]=(dp[i-1][j]%mod+dp[i-1][j-1]%mod+dp[i][j-1]%mod)%mod;
					

				}	
		}
	}
	cout<<dp[n][m]<<endl;
	ll i=n,j=m;
	stack<pair<ll,ll> > st;
	if(dp[n][m]!=0)
	{
		dfs(1,1);
	}

	

	return 0;
}