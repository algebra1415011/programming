#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
int main()
{
	ll n,q,l,r,x,y,k,type;

	scanf("%lld%lld",&n,&q);
	ll arr[n+1][2];
	for(ll i=1;i<=n;i++)
		scanf("%lld%lld",&arr[i][0],&arr[i][1]);
	for(ll i=0;i<q;i++)
	{
		scanf("%lld",&type);
		if(type==0)
		{
			scanf("%lld%lld%lld",&k,&x,&y);
			arr[k][0]=x;
			arr[k][1]=y;
		}
		else
		{
			scanf("%lld%lld%lld%lld",&l,&r,&x,&y);
			ll ans=0;
			for(ll i=l;i<=r;i++)
				ans+=max(abs(arr[i][0]-x),abs(arr[i][1]-y));
			printf("%lld\n",ans);
		}
	}

}