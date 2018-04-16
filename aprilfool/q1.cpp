#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
	ll n,cnt=0;
	cin>>n;
	ll sum=1;
	for(ll i=n+1;i>=1;i--)
	{
		sum=sum*i;
	}
	cout<<sum+n<<endl;
}