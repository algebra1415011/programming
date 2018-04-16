#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{

	ll n,m,mid;
	cin>>n>>m;
	if(m>=n)
	{
		cout<<n<<endl;
		exit(0);
	}
	ll start=0;
	ll end=1e10;
	ll l=n-m;
	ll ans=1e18;
	while(end>=start)
	{
		mid=(start+end)/2;
		ll t=(mid*(mid+1))/2;
		if(t>=l)
			{
				end=mid-1;
				ans=min(ans,mid);
			}	
		else
			start=mid+1;
		//cout<<start<<" "<<end<<endl;
	}
	cout<<ans+m<<endl;
}