#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll str[1000010];
vector<ll> v[1000010];

int main()
{

	ios::sync_with_stdio(false);
	ll n,a,b;
	cin>>n;
	ll maxi=1;
	for(ll i=0;i<n;i++)
		{
			cin>>str[i+1];
			if(str[i+1]>str[maxi])
				maxi=i+1;
		}	
	for(ll i=1;i<=n-1;i++)
	{
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);

	}
	cout<<maxi<<endl;
	set<ll> st;
	st.insert(maxi);
	while(!st.empty())
	{
		ll current
	}


	
	
	return 0;
}