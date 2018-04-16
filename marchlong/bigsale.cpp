#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
int main()
{

	ll t;
	cin>>t;
	while(t--)
	{
		ll n;

		cin>>n;
		ll price[n],quant[n],discount[n];
		double ans=0;
		double temp;
		for(ll i=0;i<n;i++)
		{
			cin>>price[i]>>quant[i]>>discount[i];

			
			ans+=quant[i]*(price[i]-((100-(discount[i]*1.0))*(((price[i]*1.0)+((price[i]*discount[i])/(100*1.0)))))/100);
		}
		printf("%.7f\n",ans);
	}
	return 0;
}