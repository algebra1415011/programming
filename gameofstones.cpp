#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll grundy[61];
map<ll,ll> dp[61];
ll gru(ll s,ll mask)
{
	
	if(s==0)
		return 0;
	if(dp[s][mask])
		{
			//cout<<"he;;p"<<endl;
			return dp[s][mask];
		}	
	ll mex=0,temp;
	for(ll i=1;i<=s;i++)
	{
		if(!(mask&(1LL<<i)))
		{
			temp=gru(s-i,(mask|(1LL<<i)));
			mex|=(1LL<<temp);
		}
	}
	ll ans=0;
	while(mex&(1LL<<ans)) ans++;
	return dp[s][mask]=ans;
}


int main()
{
	for(ll i=1;i<=60;i++)
		grundy[i]=gru(i,0LL);
	ll n,k;
	cin>>n;
	ll x=0;
	for(ll i=0;i<n;i++)
	{
		cin>>k;
		x^=grundy[k];
	}
	x==0?cout<<"YES"<<endl:cout<<"NO"<<endl;
	return 0;
}