#include <bits/stdc++.h>
#define ll long long int
using namespace std;
double dp[1001][1001];
int main()
{
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<=n;i++)
	{
		for(ll j=0;j<=m;j++)
		{
			if(i==0)
			{
					dp[0][j]=0;
					continue;
			}
			if(j==0)
			{
				dp[i][0]=1;
				continue;
			}
			 if(j-2<0){ dp[i][j]= i*1.0/(i+j); continue; }
                              
             if(j-3<0){ dp[i][j]= i*1.0/(i+j) +(j*1.0/(i+j))*((j-1)*1.0/(i+j-1))*(i*1.0/(i+j-2))*dp[i-1][j-2];  continue; }
                              else{
                                 
                              dp[i][j]=i*1.0/(i+j) +(j*1.0/(j+i))*(((j-1)*1.0)/(j+i-1))*(dp[i-1][j-2]*(1.0*i/(i+j-2))+dp[i][j-3]*(1.0*(j-2)/(i+j-2)));
                              }
                      
               }
           }
                 printf("%.9lf",dp[n][m]);

		
	

}