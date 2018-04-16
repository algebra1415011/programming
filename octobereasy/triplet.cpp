#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[200005];
ll arr[200005];

int main()
{
    ll t,n;
    scanf("%lld",&n);
	ll arr[n];
	memset(dp,-1,sizeof(dp));
	for(ll i=1;i<=n;i++)
		scanf("%lld",&arr[i]);
	ll left[n+1],right[n+1];
	ll mini=1;
	left[0]=0;
	left[1]=0;
	for(ll i=2;i<=n;i++)
	{
		if(arr[i]<arr[mini])
		{
			mini=i;
			left[i]=0;
		}
		else
		{
			left[i]=mini;

		}	
	}
	right[n]=0;
	ll maxi=n;
	for(ll j=n-1;j>=1;j--)
	{
		if(arr[j]>arr[maxi])
		{
			maxi=j;
			right[j]=0;
		}
		else
		{
			right[j]=maxi;
		}
	}
	maxi=0;
	
	for(ll i=0;i<n;i++)
		if(left[i] and right[i])
			{
				maxi=max(maxi,arr[left[i]]*arr[i]*arr[right[i]]);

				// cout<<arr[left[i]]<<" "<<arr[i]<<" "<<arr[right[i]]<<endl;
			}	
	cout<<maxi<<endl;	


}