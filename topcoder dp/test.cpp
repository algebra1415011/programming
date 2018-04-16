#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll next[1000010],pre[1000010],arr[1000010];
stack<ll> S1;
ll ans[1000010];
int main()
{
	ll n;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
		scanf("%lld",&arr[i]);
	for(ll i=1;i<n;i++)
	{
		prev[i]=0;
		while(!S.empty() && arr[S.top()]<arr[i])
			S.pop();
		if(!S.empty())
			prev[i]=S.top();
		S.push(i);
	}
	while(!S.empty())
		S.pop();
	for(ll i=n;i>=1;i--)
	{
		next[i]=-1;
		while(!S.empty() && arr[S.top()<arr[i]])
			S.pop();
		if(!S.empty())
			next[i]=s.top();
		s.push(i);
	}
	for(ll i=1;i<=n;i++)
		if(next[i]!=-1)
			ans[next[i]-i]=max(next[i]-i,i-prev[i]);
	ll sum=0;	
	for(ll i=1;i<=n;i++)
			sum+=ans[i];
	cout<<sum<<endl;	

}