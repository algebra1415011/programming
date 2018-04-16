#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll f[1000010];
ll factorial(ll n)
{
	if(n==1 || n==0)
		return 1;
	else
		return f[n]=n*factorial(n-1);
}
string ans="";
string rec(string s, ll nth)
{
	map<ll,ll> mp;
	ll index=-1;
	map<ll,ll> :: iterator it; 
	for(ll i=0;i<s.length();i++)
		mp[s[i]-'a']++;
	ll res=factorial[s.length()-1];
	cout<<res<<endl;
	for(it=mp.begin();it!=mp.end();it++)
		{
			cout<<it->first<<" "<<it->second<<endl;
			for(ll i=it->first;i<26;i++)
			{
				if(i==it->first)
					{
						res/=factorial[mp[it->first]-1];
						index=it->first;
					}	
				else
					res/=factorial[mp[it->first]];
				
			}
		}
	cout"m "<<res<<endl;	
	if(res>nth)
	{
		ans=ans+index+'a';
		string left="";
		for(ll i=0;i<26;i++)
		{
			if(i==index)
			{
				for(ll j=1;j<=mp[i]-1;j++)
					left+=i+'a';
			}
			else
			{

				for(ll j=0;j<mp[i];j++)
					left+=i+'a';

			}	

		}
		rec(left,);

	}	
	else
	{
		nth-=res;
		for(ll i=0;i<26;i++)
		{
			if(i==index)
			{
				for(ll j=0;j<mp[i];j++)
					left+=i+'a';
			}
			else
				{

					for(ll j=0;j<mp[i];j++)
						left+=i+'a';

				}	

		}
		rec(left,nth);	
	}

	
}

int main()
{
	string s;
	f[0]=1;
	f[1]=1;
	ll n;
	while(cin>>s>>n)
	{
		cout<<s<<" "<<n<<endl;
		s=s.substr(0,s.length()-1);
		sort(s.begin(),s.end());
		//cout<<s<<endl;
		//cout<<rec(s,n)<<endl;
	}	
}