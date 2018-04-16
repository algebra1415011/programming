#include <bits/stdc++.h>
#define ll long long int
#define inf 1e18
using namespace std;
vector<pair<ll,ll> > v[1000010];
ll k,x;
//set<pair <ll,ll> > st;
ll dist[1000010];
void dijsktra(ll s)
{
	dist[s]=0;ll S=0;
	
	
	set< pair<ll,ll> > st;
	st.insert(make_pair(dist[s],s));
	while(!st.empty())
	{
		//cout<<"kella"<<endl;
		ll current=st.begin()->second;
		if(!S && current<=k )
		{
			S=1;
			for(ll i=1;i<=k;i++)
			{
				if(i==current)
					continue;
				v[i].push_back(make_pair(current,x));
				v[current].push_back(make_pair(i,x));
			}

		}
		st.erase(make_pair(dist[current],current));
		//cout<<"current"<<current<<endl;
		for(ll i=0;i<v[current].size();i++)
		{
			if(v[current][i].second+dist[current]<dist[v[current][i].first])
			{
				st.erase(make_pair(dist[v[current][i].first],v[current][i].first));
				dist[v[current][i].first]=v[current][i].second+dist[current];
				st.insert(make_pair(dist[v[current][i].first],v[current][i].first));
			}
		}
	}
}

int main()
{
	ll t,n,m,s,a,b,c;
	scanf("%lld",&t);

	while(t--)
	{
		scanf("%lld%lld%lld%lld%lld",&n,&k,&x,&m,&s);
		for(ll i=0;i<=n;i++)
			{
				v[i].clear();
				dist[i]=inf;
			}	
		for(ll i=0;i<m;i++)
		{
			scanf("%lld%lld%lld",&a,&b,&c);
			v[a].push_back(make_pair(b,c));
			v[b].push_back(make_pair(a,c));
		}
		dijsktra(s);
		for(ll i=1;i<=n;i++)
			cout<<dist[i]<<" ";
		cout<<endl;
	}
}