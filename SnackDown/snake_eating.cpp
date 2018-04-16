#include <bits/stdc++.h>
#define ll long long int
#define inf 1e18
using namespace std;
// 5 8 9 10 21


int main()
{
	ll t,k,q,n;
	cin.tie(0),ios::sync_with_stdio(false);
	scanf("%lld",&t);
	while(t--)
	{

		scanf("%lld%lld",&n,&q);
		ll prefix[n+1];
		vector<ll> arr;
		for(ll i=0;i<n;i++)
			{
				scanf("%lld",&k);
				arr.push_back(k);	
			}	
		
		vector <ll>::iterator it;
		sort(arr.begin(),arr.end());
		prefix[0]=arr[0];
		for(ll i=1;i<n;i++)
			prefix[i]=arr[i]+prefix[i-1];
		for(ll i=0;i<q;i++)
		{
			scanf("%lld",&k);
			ll id=lower_bound(arr.begin(),arr.end(),k);

			ll left=0;
			ll right=n-id;
			ll val1=prefix[right];
			while(right>=left)
			{
				mid=(right+left)/2;
				if(mid==0)
				{
					mid=val1;
				}
				if(mid>=(tot-part))
				{
					right=mid+1;
				}
				else
				{
					left=mid+1;
				}

			}
			cout<<ans<<endl;



		}	