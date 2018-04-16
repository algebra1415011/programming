/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[15][15];
int rec(int k,int n)
{
	if(k==0 )
        {
        	dp[k][n]=n;
			return dp[k][n];
        
       } 
	if(dp[k][n]!=-1)
		return dp[k][n];
	dp[k][n]=0;
	for(ll i=1;i<=n-1;i++)
	{
		dp[k][n]+=rec(k-1,i);
		cout<<dp[k][n]<<endl;

	}
	return dp[k][n];

}

int main(){
	memset(dp,-1,sizeof(dp));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<" l "<<rec(2,3)<<endl;
	return 0;
}	