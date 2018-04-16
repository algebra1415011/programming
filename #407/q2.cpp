#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{

	ll b,q,l,m,k;
	cin>>b>>q>>l>>m;
	map<ll,ll> mp;
	for(ll i=0;i<m;i++)
	{
		cin>>k;
		mp[k]++;
	}
	if(abs(b)>l)
	{
		cout<<"0"<<endl;
		exit(0);
	}
	if(b==0)
	{
		if(mp[0])
		{
			cout<<"0"<<endl;
			exit(0);
		}
		else
		{
			cout<<"inf"<<endl;
			exit(0);
		}
	}
	if(q==1)
	{
		if(mp[b])
		{
			cout<<"0"<<endl;
			exit(0);
		}
		else
		{
			cout<<"inf"<<endl;
			exit(0);
		}
	}
	if(q==-1)
	{
		if(mp[b] && mp[-b])
		{
			cout<<"0"<<endl;
			exit(0);
		}
		else
		{
			cout<<"inf"<<endl;
			exit(0);
		}	
	}
	if(q==0)
	{
		if(!mp[0])
		{
			cout<<"inf"<<endl;
			exit(0);
		}
		else if(mp[b])
		{
			cout<<"0"<<endl;
			exit(0);
		}
		else 
		{
			cout<<"1"<<endl;
			exit(0);
		}

	}
	ll c=0;
	for(ll i=b;abs(i)<=l;i=i*q)
	{
		if(!mp[i])
			c++;
	}
	cout<<c<<endl;
	exit(0);


}