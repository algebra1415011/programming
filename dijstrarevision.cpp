#include <bits/stdc++.h>
#define ll long long int
#define inf 1e18 
using namespace std;
vector<pair<ll,ll> > v[1000010];
set<pair <ll,ll> > st;
ll dist[1000010];
void dijstra(ll s)
{
	st.insert(make_pair(s,0));
	dist[s]=0;
	while(!st.empty())
	{
		ll current=st.begin()->first;
		st.erase(make_pair(current,dist[current]));
		for(ll i=0;i<v[current].size();i++)
		{
			if(dist[current]+v[current][i].second<dist[v[current][i].first])
			{
				st.erase(make_pair(v[current][i].first,dist[v[current][i].first]));
				dist[v[current][i].first]=dist[current]+v[current][i].second;
				st.insert(make_pair(v[current][i].first,dist[v[current][i].first]));
			}
		}
	}
} 
int main()
{

	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n,m,a,b,c;
		
		scanf("%lld%lld",&n,&m);
		for(ll i=0;i<=n;i++)
			dist[i]=inf;
		for(ll i=1;i<=n;i++)
			v[i].clear();
		for(ll i=0;i<m;i++)
		{
			scanf("%lld%lld%lld",&a,&b,&c);
			v[a].push_back(make_pair(b,c));
			// v[b].push_back(make_pair(a,c));
		}
		ll s,x;
		scanf("%lld%lld",&s,&x);
		dijstra(s);
		// sort(dist+1,dist+n+1);
		vector<ll> pp;
		ll sum=0;
		ll count1=0;
		for(ll i=1;i<=n;i++)
		{
			 cout<<dist[i]<<endl;
			if(i!=s)
				pp.push_back(dist[i]);

			
		}
		// 
		sort(pp.begin(),pp.end());
		for(ll i=0;i<pp.size();i++)
		{
			x-=pp[i];

			if(x<0)
			{
				break;
			}
			count1++;

		}
		printf("%lld\n",count1);
	}
	
	return 0;
}