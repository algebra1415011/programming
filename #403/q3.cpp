#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll number[200010];
vector<ll> v[200010];
set<ll> st;
void dfs(ll src,ll p)
{
	
	ll t=1;
	for(ll i=0;i<v[src].size();i++)
	{
		if(v[src][i]!=p)
		{
			if(number[src]==t || number[p]==t)
					t++;
			if(number[src]==t || number[p]==t)
					t++;
			number[v[src][i]]=t;
			st.insert(t);
			t++;
			//cout<<p<<" "<<src<<" "<<v[src][i]<<" "<<number[v[src][i]]<<endl;
			dfs(v[src][i],src);
		}
	}
}



int main()
{

	ll n,a,b;
	cin>>n;
	for(ll i=1;i<n;i++)
	{
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}	
	number[1]=1;
	st.insert(1);
	dfs(1,1);
	cout<<st.size()<<endl;
	for(ll i=1;i<=n;i++)
		cout<<number[i]<<" ";
	cout<<endl;		

	return 0;
}