/*
 * Avinash Gurjar, NIT Silchar
*/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int dp[15][15];

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
	for(ll i=1;i<=n;i++)
	{
		dp[k][n]+=rec(k-1,i);

	}
	return dp[k][n];

}
class ShorterSuperSum{
public:
	 int calculate(int k, int n){
	memset(dp,-1,sizeof(dp));
	return rec(k,n);

	}
};
