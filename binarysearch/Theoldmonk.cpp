#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll arr[n],brr[n];
		for(ll i=0;i<n;i++)
			cin>>arr[i];
		for(ll i=0;i<n;i++)
			cin>>brr[i];
		ll maxi=0;
		ll ans=-1;
		
		for(ll i=0;i<n;i++)
		{
            ans=-1;
            ll high=n-1;
            ll start=0;
			 ans=-1;
			while(high>=start)
			{
				ll mid=(start+high)/2;
				if(brr[mid]>=arr[i])
				{
					ans=mid;
					start=mid+1;
				}
				else
				{
					high=mid-1;
				}
			}
			//cout<<"i"<<i<<" "<<ans<<endl;
			
				maxi=max(maxi,ans-i);
		}
		cout<<maxi<<endl;

	}

	return 0;
}