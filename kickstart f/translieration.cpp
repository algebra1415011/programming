#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{

	ll n;
	string s;
	cin>>n;
	map<string , ll > mp;
	while(n--)
	{
		cin>>s;
		for(ll i=0;i<s.length();i++)
		{
			if(s[i]=='u')
			{
				s[i]='#';
			}
			else if(i<s.length() and s[i]=='o' and s[i+1]=='o')
			{
				s[i]='#';
				s[i+1]='#';
			}
			if(i<s.length() and s[i]=='k' and s[i+1]=='h')
			{
				s[i]='@';
				s[i+1]='@';
			}
			else if(s[i]=='h')
			{
				s[i]='@';
			}

		}

		string str="";
		ll flag1=0;
		ll flag2=0;
		
		// cout<<s<<" ";
		for(ll i=0;i<s.length();i++)
		{


			 if(s[i]=='@' and flag1==0)
			{
				str+=s[i];
				flag1=1;
				
			}

			else if(s[i]=='#' and flag2==0)
			{
				// cout<<"dobara";
				str+=s[i];
				flag2=1;
				
			}
			else if(s[i]!='@' and s[i]!='#')
				{
					str=str+s[i];
					flag2=0;
					flag1=0;

				}
			
		}

		// cout<<str<<endl;
		mp[str]++;

	}

	ll c=0;
	map<string, ll >  :: iterator it;
	for(it=mp.begin() ;it!=mp.end();it++)
	{
		cout<<it->first<<endl;
	}
	cout<<mp.size()<<endl;
	return 0;
}