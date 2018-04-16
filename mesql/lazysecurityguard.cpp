#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll t;
	cin>>t;
	ll n=sqrt(t);
	ll ans=0;
	ans+=4*n;
	t-=n*n;
	ans+=2*(t/n);
	if(t%n==0)
		cout<<ans<<endl;
	else
		cout<<ans+2<<endl;

}