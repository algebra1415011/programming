#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{


	ll n,m,k,c;
	cin>>n>>m;
	ll flag=0;
	for(ll i=0;i<m;i++)
	{
		cin>>k;
		flag=0;
		map<ll,ll> mp;
		for(ll j=0;j<k;j++)
		{
			cin>>c;

			if(mp[-c])
				flag=1;
			mp[c]=1;
		}
		if(flag==0)
			{
				//cout<<i<<endl;
				break;
			}	
	}
	if(flag==0)
	{
		cout<<"YES"<<endl;
		exit(0);
	}
		cout<<"NO"<<endl;

	return 0;
}