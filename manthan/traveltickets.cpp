#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<pair<ll,ll> > v[1000001];
bool visited[1000001];
ll cost[1000001];
ll height=0;
ll section;
ll value;
map<ll,pair<ll,ll> > papa;
ll level[1000001];
ll p[1000001];
void bfs(ll s)
{
	queue<ll> q;
	q.push(s);
	visited[s]=1;
	level[s]=0;
	while(!(q.empty()))
	{
		ll current=q.front();
		//cout<<current<<" ";
		q.pop();
		for(ll i=0;i<v[current].size();i++)
		{
			if(!visited[v[current][i].first])
			{
				level[v[current][i].first]=level[current]+1;
				height=max(height,level[v[current][i].first]);
				visited[v[current][i].first]=1;
				papa[v[current][i].first].first=current;
                papa[v[current][i].first].second=v[current][i].second;
				q.push(v[current][i].first);
			}
		}
	}
}
 
 
void dfs(ll s)
{
 
 
	if(level[s]<section)
		p[s]=1;
	else if(!(level[s]%section))
		p[s]=papa[s].first;
	else
		p[s]=p[papa[s].first];
 
	visited[s]=true;
	  // cout<<s<<" "<<mon<<" "<<freeticket<< endl;
		 
	for(ll i=0;i<v[s].size();i++)
		if(!visited[v[s][i].first] )
					dfs(v[s][i].first);
}
 
 
ll query(ll x,ll y)
{
	while(p[x]!=p[y])
	{
		if(level[x]>level[y])
			x=p[x];
		else
			y=p[y];
	}
	while(x!=y)
	{
		if(level[x]>level[y])
			x=papa[x].first;
		else
			y=papa[y].first;
	}	
	return x;
}
 
 
int main()
{
	ll n,m,k,a,b,w,s,d;
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)
		scanf("%lld",&cost[i]);
	for(ll i=1;i<=n-1;i++)
	{
		scanf("%lld%lld%lld",&a,&b,&w);
		v[a].push_back(make_pair(b,w));
		v[b].push_back(make_pair(a,w));
	}
 
 
		bfs(1);
		for(ll i=0;i<=n;i++)
			visited[i]=false;
		section=sqrt(height+1);
    dfs(1);
 
	for(ll i=1;i<=m;i++)
	{
		scanf("%lld%lld",&s,&d);
        ll ancestor=query(s,d);
        ll freetickets=0;
        ll money=cost[s];
        
        map<ll,ll> mp;
        ll flag=0;
       
        //cout<<"khata"<<endl;
         while(s!=ancestor)
         {
             
             freetickets+=papa[s].second;        
             s=papa[s].first;
             mp[s]=1;
             if(freetickets>=cost[s])
                 freetickets=freetickets-cost[s];
             else
             {
                 money+=cost[s]-freetickets;
                 freetickets=0;
             }
               
         }
        //cout<<endl;
        vector<ll > vtemp;
        ll node=d;
        
        while(node!=ancestor)
        {
            // if(mp[node])
            // {
            //     flag=1;
            //     cout<<"repear"<<endl;
            //     break;
            // }
            vtemp.push_back(node);
            //cout<<node<<" ";
            node=papa[node].first;
        }
        if(flag==0)
        {
            for(ll i=vtemp.size()-1;i>=0;i--)
            {
                //cout<<"kl"<<money<<" ";
                freetickets+=papa[vtemp[i]].second;        
                if(freetickets>=cost[vtemp[i]])
                     freetickets=freetickets-cost[vtemp[i]];
                 else
                 {
                     money+=cost[vtemp[i]]-freetickets;
                     freetickets=0;
                 }
            }
        }  
        
       
		printf("%lld\n",money);
 
	}
 
 
}
 