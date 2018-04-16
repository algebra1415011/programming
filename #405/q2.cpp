#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> v[150010];
ll visit[150001];
ll tvisit[150001];
vector<ll> ans;
void dfs(ll s)
{
	visit[s]=1;
	ans.push_back(s);
	for(ll i=0;i<v[s].size();i++)
	{
		if(!visit[v[s][i]])
		{
			dfs(v[s][i]);
		}
	}	
}

int main()
{
	cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0);
	ll n,m;
	ll a,b;
	cin>>n>>m;
	

	set<ll> st;
	for(ll i=0;i<m;i++)
	{
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);

	}
	for(ll i=1;i<=n;i++)
	{
		if(!visit[i])
		{	
			ans.clear();
			dfs(i);

			ll sz=ans.size();
			for(ll j=0;j<ans.size();j++)
			{
				if(v[ans[j]].size()!=sz-1)
				{
					cout<<"NO"<<endl;
					exit(0);
				}
			}

		}	
	}
	cout<<"YES"<<endl;
	


	return 0;
}