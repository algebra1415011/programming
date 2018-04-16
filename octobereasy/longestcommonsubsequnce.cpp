#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[2005][2005];
ll arr[200005];
ll maxi=0;
ll ind=-1e18;
ll lcs(ll arr[],ll brr[],ll n,ll m)
{
   if (m == 0 || n == 0)
     return 0;
   if(dp[n][m]!=-1)
      {
        // ind=max(n-1,ind);
        return dp[n][m];

       } 
   ll ans=0; 
   if (arr[n-1] == brr[m-1])
    {
      
      
      ans= 1 + lcs(arr, brr, n-1, m-1);
      if(ans>maxi)
      {
        ind=max(ind,n-1);
        maxi=ans;
      }
    } 
   else
     ans= max(ans,max(lcs(arr, brr,n, m-1), lcs(arr, brr,n-1, m)));
   dp[n][m]=ans;
   return dp[n][m];
}
 

int main()
{
  ll n,m,k;
  cin>>n>>m>>k;

  ll arr[n], brr[m];
  for(ll i=0;i<n;i++)
    cin>>arr[i];
  for(ll i=0;i<m;i++)
    cin>>brr[i];
  memset(dp,-1,sizeof(dp));
  
  cout<<lcs(arr,brr,n,m)+min(k,n-k-1)<<endl;
 
  return 0;
}