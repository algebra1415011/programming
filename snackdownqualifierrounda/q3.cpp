#include <bits/stdc++.h>
#define ll long long int
#define inf 100000000000000000
using namespace std;
ll arr[1000010];
ll pre[1000010];
ll tr[1000010];
ll tl[1000010];
int main()
{
	ll t,n;
	scanf("%lld",&t);
	//cout<<t<<endl;
	ll maxi=0;
	while(t--)
	{
		cin>>n;	
		for(ll i=0;i<=n;i++)
		{
			arr[i]=0;
			tr[i]=0;
			tl[i]=0;
			
		}
		maxi=0;
		for(ll i=0;i<n;i++)
		{
			cin>>arr[i];

			if(i!=0)
				pre[i]=pre[i-1]+arr[i];
			else
				pre[i]=arr[i];
			
		}
		
		tl[0]=1;
		tr[n-1]=1;
		ll res=inf;
		for(ll i=1;i<n;i++)
		{
			if(arr[i]>tl[i-1])
			{
				tl[i]=tl[i-1]+1;

			}
			else
				tl[i]=arr[i];

		}
		for(ll i=n-2;i>=0;i--)
		{
			if(arr[i]>tr[i+1])
				tr[i]=tr[i+1]+1;
			else
				tr[i]=arr[i];
		}

		for(ll i=0;i<n;i++)
		{
			arr[i]=min(tl[i],tr[i]);
			res=min(res,pre[n-1]-arr[i]*arr[i]);	
		}
		cout<<res<<endl;

		
		
	}
	return 0;
}