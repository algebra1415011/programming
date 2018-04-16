#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0);
	ll a,b;
	cin>>a>>b;
	ll i=1;
	for( i=1;;i++)
	{
		a=3*a;
		b=b*2;
		if(a>b)
			break;
	}
	cout<<i<<endl;


	return 0;
}