#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
map<ll,ll> mp;
int main()
{

	ll n,t,v;
	char c;
	cin>>n;
	ll ind=0;
	ll ans=0;
	vector<pair<char,ll> > v1;
	for(ll i=0;i<n;i++)
	{

		cin>>c>>v;
		
		v1.push_back(make_pair(c,v));
	}
	char c=v[v.size()-1].first;
	if(c=='|')
		ans=1;
	else
		ans=0;
	for(ll i=v.size()-2;i>=0;i--)
	{

		
			c=v[i].first;
			if(c=='^')
			{
				if(!mp[(ans^v)])
					{
						mp[ans^v]=i;
						ans=ans^v;
					}	
				else
					{
						v1.push_back(make_pair(c,v));
						ind=mp[ans^v];
						

					}	
			}
			else if(c=='|')
			{
				if(!mp[(ans || v)])
				mp[(ans||v)]=i,ans=(ans || v);
				else

					{
						v1.push_back(make_pair(c,v));
						ind=mp[(ans||v)];
						

					}
			}
			else if(c=='&')	
			{
				if(!mp[(ans&&v)])
				mp[(ans&&v)]=i,ans=(ans && v);
				else
					{
						v1.push_back(make_pair(c,v));
						ind=mp[(ans&&v)];
						

					}
			}

		
		 cout<<ans<<" ";
		v1.push_back(make_pair(c,v));
	}







	cout<<v1.size()<<endl;
	for(ll i=0;i<v1.size();i++)
	{
		cout<<v1[i].first<<" "<<v1[i].second<<endl;
	}
	
	
	
	return 0;
}