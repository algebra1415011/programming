#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll nexty[1000010],previous[1000010],arr[1000010];
stack<ll> S;
ll ans[1000010];
int main()
{
	ll n;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
		scanf("%lld",&arr[i]);
	for(ll i=1;i<=n;i++)
	{
		previous[i]=0;
		while(!S.empty() && arr[S.top()]<arr[i])
			S.pop();
		if(!S.empty())
			previous[i]=S.top();
		S.push(i);
	}
	while(!S.empty())
		S.pop();
	for(ll i=n;i>=1;i--)
	{
		nexty[i]=-1;
		while(!S.empty() && arr[S.top()]<arr[i])
			S.pop();
		if(!S.empty())
			nexty[i]=S.top();
		S.push(i);
	}
	for(ll i=1;i<=n;i++)
		if(nexty[i]!=-1)
			ans[nexty[i]-i]=max(ans[nexty[i]-i],i-previous[i]);
	ll sum=0;	
	for(ll i=1;i<=n;i++)
			sum+=ans[i];
	cout<<sum<<endl;	

}