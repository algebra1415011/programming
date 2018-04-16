#include <bits/stdc++.h>
#define  ll long long int 
using namespace std;
int main()
{

	ll t;
	cin>>t;
	
	while(t--)
	{
		ll n;
		cin>>n;
		ll arr[n];
		set<ll> st;
		for(ll i=0;i<n;i++)
		{
			cin>>arr[i];
			st.insert(arr[i]);

		}
		cout<<n-st.size()<<endl;

	}
	return 0;

}