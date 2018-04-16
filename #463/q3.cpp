#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
ll num1[1000005];
ll num2[1000005];
ll mp[1000005];
int main()
{

	ios_base::sync_with_stdio(0);
	
	ll t;
	cin>>t;
	ll flag=0;
	while(t--)
	{
		ll n;
		cin>>n;
		flag=0;
		for(ll i=1;i*i<=1e9;i++)
		{

			if((i*i)>=n)
			{
				ll rem=i*i-n;
				ll sqr=sqrt(rem);
				if(sqr!=0)
				{
					ll p=(i/sqr);
					// cout<<"p"<<p<<endl;
					if(sqr*sqr==rem and sqr>=1 and sqr<=1e9 and p>=1 and (i/p)==sqr)
					{
						cout<<i<<" "<<i/sqr<<endl;
						flag=1;
						break;
					}
				}
			}
			


		}
		if(flag==0)
		{
			cout<<-1<<endl;
		}
		// cout<<"-1"<<endl;
	}
	return 0;
}