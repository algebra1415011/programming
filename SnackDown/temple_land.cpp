#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ll sum=0;
		ll flag=0;
		if(n%2==0)
		{
			flag=1;
		}
		ll k;

		for(ll i=0;i<n;i++)
		{
			cin>>k;
			sum+=k;
		}
		if(flag==1)
		{
			cout<<"no"<<endl;
		}
		else
		{
			ll value=n/2;
			value=value*(value+1);
			value+=n/2+1;

			if(sum==value)
			{
				cout<<"yes"<<endl;
			}
			else
				cout<<"no"<<endl;
		}
	}

	return 0;
}