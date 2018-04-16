#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
int main()
{


	ll n,k;
	cin>>n>>k;
	ll arr[n];
	map<ll,ll> mp;
	ll maxi=0;
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
		if(i>=0)
		{
			if(arr[i]>maxi)
			{
				maxi=arr[i];
				mp[arr[i]]++;
				if(mp[arr[i]]==k)
				{
					cout<<arr[i]<<endl;
					return 0;
				}
			}
			else
				{
					mp[maxi]++;
					if(mp[maxi]==k)
				{
					cout<<maxi<<endl;
					return 0;
				}
				}
		}
		else
			maxi=arr[0];
	}
	maxi=0;
	
	for(ll i=0;i<n;i++)
	{
		if(maxi==mp[i+1])
		{
			maxi=i+1;
			continue;
		}
		maxi=max(maxi,mp[i+1]);
	}
	cout<<maxi<<endl;
	
	
	
	return 0;
}