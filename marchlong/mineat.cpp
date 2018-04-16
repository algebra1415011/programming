#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

ll pile[1000000];
ll n,k;
ll Search(ll low, ll high)
{
	ll mid=0;
	ll mini=1e18;
	while(low<=high)
	{
		mid=(low+high)/2;
		// cout<<mid<<endl;
		ll cnt=0;
		for(ll i=0;i<n;i++)
		{

			if(pile[i]%mid==0)
				cnt+=pile[i]/mid;
			else
				cnt+=(pile[i]/mid)+1;
		}
		if(cnt<=k)
		{
			high=mid-1;
			mini=min(mid,mini);
			
			
		}
		else
			{
				low=mid+1;

				
			}	


	}
	return mini;
}
int main()
{

	ll t;
	cin>>t;
	while(t--)
	{
		
		cin>>n>>k;
		
		ll sum=0;
		for(ll i=0;i<n;i++)
		{
			cin>>pile[i];
			sum+=pile[i];
		}
		cout<<Search(1,sum)<<endl;


	}

	return 0;
}