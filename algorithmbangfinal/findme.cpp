#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll BIT[1000010];
vector<ll> arr;
ll n;
void update(ll ind,ll res)
{
	for(ll i=ind;i<=n;i+=(i&(-i)))
		BIT[i]+=res;
}
ll query(ll ind)
{
	ll sum=0;
	for(ll i=ind;i>=1;i-=(i&(-i)))
		sum+=BIT[i];
	return sum;
}

int main()
{
	ll q,p;
	cin>>n>>q;
	//arr[0]=100000000;
	for(ll i=1;i<=n;i++)
		{
			cin>>p;
			arr.push_back(p);
			update(i,1);
		}
	
	//
	sort(arr.begin(),arr.end());
	
	ll k=0;	
	for(ll i=0;i<q;i++)
	{
		cin>>k;
		ll start=1;
		ll end=n;
		ll mini=1000000000;
		while(start<=end)
		{
			ll mid=(start+end)/2;
			//cout<<"min"<<query(mid)<<endl;
			
			if(query(mid)>=k)
			{
				mini=min(mini,mid);
				end=mid-1;
			}
			else
				start=mid+1;
		}
		cout<<arr[mini-1]<<endl;
		update(mini,-1);

	}		

}