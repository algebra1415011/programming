#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> v[1000010];
ll node1,node2,ikbari,iikbari;
vector<ll> ans;
ll l=0;
void dfs(ll src,ll p)
{
	//cout<<src<<" "<<p<<endl;
	if(l==0)
		ans.push_back(src);
	for(ll i=0;i<v[src].size();i++)
	{
		if(v[src][i]!=p)
			dfs(v[src][i],src);
	}
	if(!node1 && ikbari)
		node1=src;
	if(!node2 && iikbari)
		node2=src;
	l=1;
}
int main()
{
	ll n,m;
	cin>>n;
	ll a,b;
	for(ll i=1;i<=(n-1);i++)
	{
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	l=1;
	ikbari=1;
	dfs(1,0);
	//cout<<node1<<endl;
	iikbari=1;
	l=0;
	dfs(node1,0);
	//cout<<node2<<endl;
	/*for(ll i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";*/
	ll len=ans.size()/2;
	cout<<1<<endl;
	cout<<ans[len/2]<<" "<<ans[len+len/2-1]<<endl;
	

}