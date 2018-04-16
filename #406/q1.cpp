#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{

	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	ll flag=0;
	ll a1=a;
	ll b1=b;
	ll c1=c;
	ll d1=d;
	for(ll i=0;i<=100;i++)
	{
		b=b1+a*i;
		
			//cout<<b<<endl;

		for(ll j=0;j<=100;j++)
		{	
			d=d1+c*j;
			
				//cout<<d<<" ";
			if(b==d)
			{
				cout<<b<<endl;
				flag=1;
				break;
			}
		}
		if(flag)
		break;	

	}
	if(flag==0)
		cout<<"-1"<<endl;

	return 0;
}