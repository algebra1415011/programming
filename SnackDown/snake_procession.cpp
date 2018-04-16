#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		string s;
		ll len;
		cin>>len;
		cin>>s;
		ll c=0;
		//cout<<s<<endl;
		ll flag=0;
		for(ll i=0;i<len;i++)
		{
			if(s[i]=='H')
			{
				if(c==1)
				{
					cout<<"Invalid"<<endl;
					flag=1;
					break;
				}
				c=1;
			}
			if(s[i]=='T')
			{
				if(c==0)
				{
					cout<<"Invalid"<<endl;
					flag=1;
					break;
				}
					c=0;
			}		
		}
		if(flag==0)
			{
				if(c==1)
					cout<<"Invalid"<<endl;
				else
					cout<<"Valid"<<endl;
			}	
		}	

		return 0;
		
}