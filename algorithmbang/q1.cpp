#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll n,m;
	cin>>n;
	while(n--)
	{	
		string s;
		cin>>s;
		if(s.length()!=10)
		{
			cout<<"NO"<<endl;
			continue;
		}
		if(s[0]=='0')
			{
				cout<<"NO"<<endl;
				continue;
			}
		ll flag=0;	
		for(ll i=0;i<s.length();i++)
		{
			ll p=s[i]-'0';

			if(p>=0 && p<=9)
				continue;
			flag=1;
		}
		if(flag)
			cout<<"NO"<<endl;
		else
		cout<<"YES"<<endl;
	}	
	return 0;

}