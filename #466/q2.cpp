#include <bits/stdc++.h>
#define ll long long int 
using namespace std;


int main()
{

	ios_base::sync_with_stdio(0);
	ll n,k,a,b;
	cin>>n>>k>>a>>b;
	if(k==1 or k>n)
	{
		cout<<(n-1)*a<<endl;
		return 0;

	}
	ll x=n;
	ll sum=0;
	while(x)
	{
		if(x>=k)
		{
			ll val=(x/k)*k;
			sum+=(x-val)*a;
			x=x/k;
			sum+=min(b,(x*k-x)*a);
		}
		else
		{
			sum+=(x-1)*a;
			break;
		}

	}
	cout<<sum<<endl;

	



	return 0;

}