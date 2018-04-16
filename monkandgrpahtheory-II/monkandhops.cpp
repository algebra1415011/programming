#include <bits/stdc++.h>
#define ll long long int
#define inf 1e18
using namespace std;
ll mini=INT_MAX;

vector<pair<ll,ll> > v[100001];
vector<pair<ll,ll> > pre[100001];
set<pair<ll,ll> > st;
ll dist[100001];
void dijstra(ll s)
{
	
	dist[s]=0;
	st.insert(make_pair(s,0));
	while(!st.empty())
	{
		ll current=st.begin()->first;
		ll di=st.begin()->second;
		st.erase(make_pair(current,di));
		for(ll i=0;i<v[current].size();i++)
		{
			if(dist[current]+v[current][i].second<=dist[v[current][i].first])
			{
				
				if(dist[current]+v[current][i].second==dist[v[current][i].first])
					pre[v[current][i].first].push_back(make_pair(current,v[current][i].second));
				else
				{
					st.erase(make_pair(v[current][i].first,dist[v[current][i].first]));
					dist[v[current][i].first]=dist[current]+v[current][i].second;
					st.insert(make_pair(v[current][i].first,dist[v[current][i].first]));
					pre[v[current][i].first].clear();
					pre[v[current][i].first].push_back(make_pair(current,v[current][i].second));
				}
			}
		}
	}
}

void bfs(ll s)
{
	queue< pair< ll,pair<ll,ll> > > q;
	q.push(make_pair(s,make_pair(0,-1)));
	//visited[s]=1;
	while(!q.empty())
	{
		ll current=q.front().first;
		ll hop=q.front().second.first;
		ll val=q.front().second.second;
		//cout<<current<<" "<<hop<<" "<<val<<endl;
		q.pop();
		if(current==1)
			mini=min(mini,hop);
		
		for(ll i=0;i<pre[current].size();i++)
		{

			if(val==-1)
				q.push(make_pair(pre[current][i].first,make_pair(hop,pre[current][i].second)));
			else
			{
				
					//cout<<val<<" "<<pre[current][i].second<<endl;
					if(val%2 and pre[current][i].second%2==0 or val%2==0 and pre[current][i].second%2)
						q.push(make_pair(pre[current][i].first,make_pair(hop+1,pre[current][i].second)));
					else
						q.push(make_pair(pre[current][i].first,make_pair(hop,pre[current][i].second)));

					
			}
		}
	}

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cerr.tie(0);
	ll n,q,a,b,d;
	scanf("%lld%lld",&n,&q);
	for(ll i=0;i<=n;i++)
		dist[i]=inf;
	for(ll i=0;i<q;i++)
	{
		scanf("%lld%lld%lld",&a,&b,&d);
		v[a].push_back(make_pair(b,d));
		v[b].push_back(make_pair(a,d));
	}
	dijstra(1);
	printf("%lld ",dist[n] );
	
	bfs(n);
	printf("%lld\n",mini);
}