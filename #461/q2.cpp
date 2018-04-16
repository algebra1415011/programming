#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
int main()
{

	unsigned long long int p=67405553164731000000;
	ll ans=0;
	ll i=0;

	while(p)
	{
		ans=ans*10+(p%10)*8*i;
		i++;
		p=p/10;
	}
	cout<<p<<endl;
	return 0;
}