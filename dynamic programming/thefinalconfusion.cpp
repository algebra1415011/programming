#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[32][32];
ll confusion(ll d,ll i)
{
	
	if(i<d)
		return 0;
	if(d<0 || i<0)
		return 0;
	if(d==0 && i==0)
		return 1;
	
	//cout<<d<<" "<<i<<endl;
	if(dp[d][i])
		return dp[d][i];
	dp[d][i]=confusion(d-1,i)+confusion(d,i-1);
	return dp[d][i];		 
}
int main()
{
	ll t,k;
	dp[1][1]=1;
	dp[1][0]=1;

	confusion(31,31);
	
	scanf("%lld",&t);
	for(ll i=0;i<t;i++)
	{
		scanf("%lld",&k);
		cout<<dp[k][k]<<endl;
	}


}