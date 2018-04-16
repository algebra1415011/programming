#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{

	ll n,m,p;
	cin>>n>>m;
	ll arr[n];
	ll sum=0;
	for(ll i=0;i<n;i++)
	{

		cin>>arr[i];
		sum+=ceil(arr[i]/(1.0*m));
	}	
	ll ans=ceil(sum/(1.0*2));
	cout<<ans<<endl;


}