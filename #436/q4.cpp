#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{

	set<ll> st;
	map<ll,ll> mp;
	ll n;
	
	cin>>n;ll arr[n];
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
		mp[arr[i]]++;


	}

	for(ll i=1;i<=n;i++)
	{
		if(!mp[i])
			st.insert(i);
		

	}

	ll c=0;
	map<ll,bool> allow;
	for(ll i=0;i<n;i++)
	{
		ll val=*st.begin();
		if((mp[arr[i]]>1 and val<arr[i]) || allow[arr[i]])
		{
			c++;
			mp[arr[i]]--;
			arr[i]=val;
			st.erase(val);
			
		}
		else
		{
			allow[arr[i]]=true;
		}
	}
	
	cout<<c<<endl;
	for(ll i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}