#include <bits/stdc++.h>
#define ll long long int
using namespace  std;
int main()
{

	ll r,c,k;
	cin>>r>>c;
	ll maxii=0,maxi=INT_MAX;
	for(ll i=0;i<r;i++)
	{
		maxi=INT_MAX;
		for(ll j=0;j<c;j++)
		{
			cin>>k;
			maxi=min(k,maxi);
		}
		maxii=max(maxii,maxi);
	}
	cout<<maxii<<endl;
	return 0;
}