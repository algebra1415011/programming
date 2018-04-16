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
			it=lower_bound(arr.begin(),arr.end(),k);
			ll right1=it-arr.begin();
			ll right=right1-1;
			ll left=0;
			ll ans=n-right1;
			ll mid;
			ll val1=prefix[right];
			ll part;
			while(right>=left)
			{	
				mid=(left+right)/2;
				//cout<<left<<" "<<right<<" "<<mid<<endl;
				ll tot=(right1-mid)*k;
				//cout<<,tot<<endl;
				if(mid==0)
				{
					part=val1;
				}
				else
				part=val1-prefix[mid-1];
				//cout<<mid<<endl;
			
				if(mid>=(tot-part))
				{
					ans= n-mid;
					right=mid-1;
					
				}
				else
					left=mid+1;
			}
			//cout<<mid<<endl;
			//cout<<n<<endl;
			//cout<<"ans"<<ans<<endl;
			printf("%lld\n",ans);
			
		}
		
	}
}