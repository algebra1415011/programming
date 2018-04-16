#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> v[10000];
ll cnt[10000];
void dfs(int src,int p)
{
	int c=1;
	cout<<src<<endl;
	for(ll i=0;i<v[src].size();i++)
	{
		if(v[src][i]!=p)
		{
		
			dfs(v[src][i],src);
			c+=cnt[v[src][i]];
			
		}
	}
	cnt[src]=c;
	//cout<<src<<" "<<cnt[src]<<endl;
	
}

int main()
{
	ll a,b,n;
	cin>>n;
	cout<<n<<endl;
	for(ll i=1;i<n;i++)
	{
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,1);
	for(ll i=1;i<=n;i++)
	{
		cout<<cnt[i]<<" ";
	}

}