#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<pair<ll,ll> > v[1000001];
set<pair<ll,ll> > st;
ll d[1000001];

void dijstra(ll u)
{
		d[u]=0;
		st.insert(make_pair(0,u));
		while(!st.empty())
		{
			ll current_vertex=st.begin()->second;
			
            st.erase(st.begin());
		
			for(ll i=0;i<v[current_vertex].size();i++)
			{
				if((d[current_vertex]+v[current_vertex][i].second)<d[v[current_vertex][i].first]){
				    
					st.erase(make_pair(d[v[current_vertex][i].first],v[current_vertex][i].first));
                    d[v[current_vertex][i].first]=d[current_vertex]+v[current_vertex][i].second;
                    
					st.insert(make_pair(d[v[current_vertex][i].first],v[current_vertex][i].first));
				}
			}
			
		}
}

int main()
{
	ll n,m,x,y,dist;
	cin>>n>>m;
	for(ll i=0;i<=n;i++)
		d[i]=INT_MAX;
	for(ll i=1;i<=m;i++)
	{
		cin>>x>>y>>dist;
		//cout<<x<<" "<<y<<endl;
		v[x].push_back(make_pair(y,dist));
		v[y].push_back(make_pair(x,dist));
	}
	dijstra(1);
    
	for(ll i=1;i<=n;i++)
        cout<<d[i]<<" ";
    cout<<endl;
	return 0;
}