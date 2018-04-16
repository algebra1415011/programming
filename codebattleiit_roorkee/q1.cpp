#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{

	ll n;
	cin>>n;
	string s;
	ll flag=0;
	for(ll i=0;i<n;i++)
		{
			cin>>s;
			ll c=0;
			flag=0;
			for(ll j=1;j<s.length();j++)
			{
				if(s[j-1]=='O' && s[j]=='R')
					{
						c++;
					}	
				
						
			}
			cout<<c<<endl;

		}	
}