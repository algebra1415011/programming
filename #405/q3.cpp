#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> v[150010];
int main()
{
	cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0);
	ll n,k;
	string st[200];
	char c='A';
	for(ll i=1;i<=26;i++)
	{
		st[i]=c;
		c++;	
	}
	//cout<<c<<endl;
	ll j=1;
	for(ll i=27;i<=51;i++)
	{
		st[i]=st[j]+'x';
		//cout<<c<<" ";
		j++;
		c++;
	}
	c='a';
	 j=1;
	for(ll i=52;i<=77;i++)
	{
		st[i]=st[j]+char(c);
		j++;
		c++;
	}
	c='a';
	j=1;
	for(ll i=78;i<=101;i++)
	{
		st[i]=st[j]+char('a');
		j++;
		c++;
	}
	//cout<<c<<endl;
	for(ll i=1;i<=101;i++)
	{
		//cout<<st[i]<<" ";
	}
	cin>>n>>k;
	ll b=n-k+1;
	string s[b+1];
	
	for(ll i=1;i<=b;i++)
	{
		cin>>s[i];
	}
	for(ll i=1;i<=b;i++)
	{
		if(s[i]=="NO")
		{
			st[i+k-1]=st[i];
		}
	}
	for(ll i=1;i<=n;i++)
		cout<<st[i]<<" ";
		cout<<endl; 
	

	return 0;
}