#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
int main()
{

	ll n,m;
	cin>>n>>m;
	string s;
	map<string ,ll> mp;
	for(ll i=0;i<n;i++)
	{
		cin>>s;
		mp[s]=1;
	}
	ll c=0;
	for(ll i=0;i<m;i++)
	{
		cin>>s;
		if(mp[s])
			c++;
	}
	
	n=n-c;
	m=m-c;
	if(c%2==1)
	{
		n++;
		
		if(m>=n)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
		exit(0);

	}
	if(n>m)
	cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;		

	
	
	




}