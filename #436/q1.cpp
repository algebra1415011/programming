#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{

	ll t,n;
	ll k;
	set<ll> st;
	cin>>n;
	map<ll,ll> mp;
	ll sum=0;
	for(ll i=0;i<n;i++)
	{
		cin>>k;
		st.insert(k);
		sum+=k;
		mp[k]++;
	}
	if(st.size()!=2)
	{
		cout<<"NO"<<endl;
	}
	else
	{

		
		set<ll> :: iterator it;
		map<ll,ll> :: iterator mpit;
		ll prev=0,flag=0,sec=0;
		for(mpit=mp.begin();mpit!=mp.end();mpit++)
		{
			
				if(flag==0)
					{
						prev=mpit->first;
						flag=1;
					}	
				else
					sec=mpit->first;


		}

		if(mp[prev]==mp[sec])
		{
			cout<<"YES"<<endl;
			for(it=st.begin();it!=st.end();it++)
		{
			 cout<<*it<<" ";


		}
	}
		else{
			cout<<"NO"<<endl;
		}
		
		
		
	}
	return 0;
}