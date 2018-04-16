#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{

	ll n,m,k;
	ll arr[10001];
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++)
		{
			cin>>arr[i];

		}
		ll mini=INT_MAX;
	for(ll i=m-1;i>=1;i--)
	{
		if(arr[i]!=0)
		{
			if(arr[i]<=k)
			{
				mini=(m-i)*10;
				//cout<<i<<endl;
				break;
			}
		}
	}	
	for(ll i=m+1;i<=n;i++)
	{
		if(arr[i]!=0)
		{
			if(arr[i]<=k)
			{
				//cout<<arr[i]<<endl;
				mini=min(mini,(i-m)*10);
				break;
			}
			
		}
	}	
	cout<<mini<<endl;
	return 0;
}