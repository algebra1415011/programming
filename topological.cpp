#include <bits/stdc++.h>
#define ll long long int
using namespace std;
bool visited[10001];
bool temporary[10001];
vector<ll> v[10001];
ll mp[10001];
bool dfs(ll src)
{
	if(!visited[src])
	{
		visited[src]=true;
		temporary[src]=true;
		for(ll i=0;i<v[src].size();i++)
		{
			if(!visited[v[src][i]] && dfs(v[src][i]))
				return true;
			else if(temporary[v[src][i]])
				return true;
		}
	}
	temporary[src]=false;
	return false;
}

int main()
{

	ios::sync_with_stdio(false);
	ll n,m,a,b;
	
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=m;i++)
	{
		scanf("%lld%lld",&a,&b);
		v[a].push_back(b);
		mp[b]++;
	}
	set<ll> st;
	for(ll i=1;i<=n;i++)
		if(dfs(i))
		{
			printf("Sandro fails.\n");
						exit(0);
		}
	for(ll i=1;i<=n;i++)
		if(mp[i]==0)
			st.insert(i);
	while(!st.empty())
	{
		b=(*st.begin());
		st.erase(b);
		cout<<b<<" ";
		for(ll i=0;i<v[b].size();i++)
			if(--mp[v[b][i]]==0)
				st.insert(v[b][i]);
	}



	return 0;
}