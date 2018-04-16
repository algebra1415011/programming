#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
int main()
{

	ll t,a,b,c,d;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		for(ll i=0;i<b;i++)
		{
			cin>>c>>d;
		}
		if(a%2==0)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
}