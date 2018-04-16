#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{

	ios_base::sync_with_stdio(0);
	ll n;
	cin>>n;
	ll arr[n+1];
	for(ll i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	ll mi=1e18;
	arr[0]=1;
	arr[n+1]=1000000;
	for(ll i=0;i<=n;i++)
	{
		mi=min(mi,max(arr[i]-1,1000000-arr[i+1]));
	}
	cout<<mi<<endl;
	return 0;
}