#include <bits/stdc++.h>
#define ll long long int
using namespace std;
pair<ll,pair<ll,ll> > p[1000010];
ll minimumcost=0;
ll par[1000010];
ll sz[1000010];
ll findp(ll pr)
{
	if(par[pr]==pr)
		return pr;
	else
		return par[pr];

}
void union_baba(ll a,ll b)
{
	ll roota=findp(a);
	ll rootb=findp(b);
	if(sz[rootb]>=sz[roota])
	{
		par[roota]=rootb;
		sz[rootb]+=sz[roota];
	}
	else
	{
		par[rootb]=roota;
		sz[roota]+=sz[rootb];
	}

}

ll kruskal_ko_bulao(ll edges)
{
	for(ll i=0;i<edges;i++)
	{
		ll u=p[i].second.first;
		ll v=p[i].second.second;
		if(findp(u)!=findp(v)){union_baba(u,v);minimumcost+=p[i].first;}
	}
	return minimumcost;
}

int main()
{
	cin.tie(0),cerr.tie(0), ios_base:: sync_with_stdio(0);
	ll vertex,edges,x,y,w;
	cin>>vertex>>edges;
	for(ll i=0;i<=vertex;i++)
	{
		par[i]=i;
		sz[i]=1;
	}
	for(ll i=0;i<edges;i++)
	{
		cin>>x>>y>>w;
		p[i]=make_pair(w,make_pair(x,y));
	}
	sort(p,p+edges);
	cout<<kruskal_ko_bulao(edges)<<endl;
	return 0;
}