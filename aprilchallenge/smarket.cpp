#include <bits/stdc++.h>
#define ll long long int
#define inf 1e18
using namespace std;
vector<ll> v[100005];
ll papa[100005];
ll final[100005];
ll upper_bound(ll data,ll degree)
{
	ll low=0;
	ll mid;
	
	ll high=v[degree].size()-1;
	ll ans=inf;
	while(high>=low)
	{
		//cout<<low<<" "<<high<<endl;
		mid=(low+high)/2;
		if(v[degree][mid]>data)
		{
			ans=min(ans,mid);
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	if(ans==inf)
		return -1;
	return ans;
}

ll lower_bound(ll data,ll degree)
{	
	ll low=0;
	ll ans=inf;
	ll mid;
	ll high=v[degree].size()-1;

	while(high>=low)
	{
		//cout<<low<<" "<<high<<endl;
		mid=(low+high)/2;
		if(v[degree][mid]>=data)
		{
			ans=min(ans,mid);
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	if(ans==inf)
		return -1;
	return ans;
}


int main()
{
	cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0);
	ll t,n,q,a,b,degree;
	cin>>t;
	while(t--)
	{
		cin>>n>>q;
		ll arr[100005];
		for(ll i=1;i<=n;i++)
			cin>>arr[i];
		for(ll i=0;i<=n;i++)
		{
			v[i].clear();
			papa[i]=0;
			final[i]=0;
		}
		
		
		for(ll i=1;i<=n;i++)
		{
			if(arr[i]==arr[i-1])
				papa[i]=papa[i-1]+1;
			else
				papa[i]++;

		}
		ll flag=0;
		final[n]=n;
		//cout<<endl;
		for(ll i=n;i>=1;i--)
		{
			if(papa[i]<=papa[i-1])
			{
				//cout<<i-1<<" ";
				final[i-1]=i-1;
			}
			else
				final[i-1]=final[i];	
		}
		
		ll ans=0;		
		for(ll i=1;i<=n;i++)
				v[papa[i]].push_back(i);

		for(ll i=0;i<q;i++)
		{
			cin>>a>>b>>degree;
			ans=0;
			if(v[degree].size()==0)
			{
				cout<<0<<endl;
				continue;
			}
			if(final[a]<=b && final[a]-a+1>=degree)
			{
				ans++;
				ll l=lower_bound(final[a]+1,degree);
				ll u=upper_bound(b,degree);
				//cout<<l<<" "<<u<<endl;
				if(l==-1 && u==-1)
				{
					cout<<ans<<endl;
					continue;
				}
				if(l!=-1)
				{
					if(u==-1)
						{
							u=v[degree].size()-1;
							if(l>=0 && u>=0 && l<=u)
								ans+=u-l+1;
							cout<<ans<<endl;
							continue;
						}	
					else if(u==0)
						{
							cout<<ans<<endl;
							continue;
						}
					else
					{
							u--;
							if(l>=0 && u>=0 && l<=u)
								ans+=u-l+1;
							cout<<ans<<endl;
							continue;
					}		
				}



			}
			else
			{
				//cout<<"c"<<endl;
				ll l=lower_bound(final[a]+1,degree);
				ll u=upper_bound(b,degree);
				if(u==-1 && l>=0)
					u=v[degree].size()-1;
				else
					u--;
				//cout<<l<<" "<<u<<endl;
				if(final[a]-a+1>=degree)
					ans++;
				if(l<=u && u>=0 && v>=0)
					ans=u-l+1;

				cout<<ans<<endl;
				continue;
			}


				

		}
	}

}
/*
2
2
0
1
3
1
1
*/