#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
vector<ll> v[26];
int main()
{



	ll t;
	cin>>t;
	while(t--)
	{
		string s;
		for(ll i=0;i<26;i++)
		     v[i].clear();
		cin>>s;
		
		s="@"+s;
		for(ll i=1;i<s.length();i++)
			{
				ll u=s[i]-'a';
				v[u].push_back(i);
				
			}
		 	
		ll c=1;
		ll sum=0;
		
		for(ll i=0;i<26;i++)
		{
			for(ll j=1;j<v[i].size();j++)
			{
				if((v[i][j]-v[i][j-1])==1)
				{
					c++;
					continue;
				}
				else
				{

					sum+=(c*(c-1))/2;
					c=1;
					set<char> st;
					for(ll k=v[i][j-1]+1;k<=v[i][j]-1;k++)
					{
						st.insert(s[k]);
					}
					if(st.size()==1)
					{
						sum++;
					}
				}
			}
			sum+=(c*(c-1))/2;
				c=1;
		}


		cout<<sum<<endl;
	}

	return 0;
}