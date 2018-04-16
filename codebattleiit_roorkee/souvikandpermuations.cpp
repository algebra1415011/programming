#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
ll inverse(ll a)
{
	ll b=mod-2;
	ll ans=1;
	while(b)
	{
		if(b%2==1)
		{
			ans=(ans*a)%mod;
		}
		a=(a*a)%mod;
		b=b/2;
	}
	return ans;
}


int main()
{

	ll n;
	cin>>n;
	string s;
	ll ans=1;
	for(ll i=0;i<n;i++)
	{
		cin>>s;
		ll v=0;
		ll c=0;
		ans=1;
		map<char,int> mp;
		for(ll i=0;i<s.length();i++)
		{
			if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' )
				v++;
			else
				c++;
			mp[s[i]]++;

		}

		for(ll i=c;i>=1;i--)
		{
			ans=(ans*i)%mod;
		}
		for(ll i=v;i>=1;i--)
		{
			ans=(ans*i)%mod;
		}
		//cout<<"a"<<ans<<endl;
		for(char i='a';i<='z';i++)
		{
			if(mp[i]>=2)
			{
				c=1;
				//cout<<i<<" "<<mp[i]<<endl;
				for(ll j=mp[i];j>=1;j--)
					c=(c*j)%mod;
				//cout<<"c"<<c<<endl;	
				ans=(ans%mod*inverse(c)%mod)%mod;

			}	
		}
		cout<<ans<<endl;


	}
	return 0;
}