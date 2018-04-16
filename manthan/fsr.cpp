#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
int main()
{
	ll n,m;
	cin>>n>>m;
	ll ans;
	ll res;
	ll a[10]={0},b[10]={0};
	for(ll i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		a[x]++;
	}
	for(ll i=0;i<m;i++)
	{
		ll x;
		cin>>x;
		b[x]++;

	}
	for(ll i=1;i<10;i++)
	{
		if(a[i]>0 and b[i]>0)
		{
			cout<<i<<endl;
			exit(0);
		}
	}
	for(ll i=1;i<10;i++)
	{
		if(a[i]>0)
			{ans=i;break;}
	}
	ans*=10;
	for(ll i=1;i<10;i++)
	{
		if(b[i]>0)
		{
			ans+=i;
			break;
		}
	}
	
	for(ll i=1;i<10;i++)
	{
		if(b[i]>0)
			{res=i;break;}
	}
	res*=10;
	for(ll i=1;i<10;i++)
	{
		if(a[i]>0)
		{
			res+=i;
			break;
		}
	}
	cout<<min(ans,res)<<endl;

return 0;
}