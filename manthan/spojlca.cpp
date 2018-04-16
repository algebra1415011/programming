#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> v[1001];
ll papa[1001];
ll level[1001];
ll visited[1001];
ll p[1001];
ll height=0;
ll section;



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
    
 	//eulertoor.push_back(s);
	
	visited[s]=true;
	  // cout<<s<<" "<<mon<<" "<<freeticket<< endl;
	for(ll i=0;i<v[s].size();i++)
		if(!visited[v[s][i].first] )
        {
           leveleulertoor.push_back(level[s]);
            eulertoor.push_back(s);
            dfs(v[s][i].first);
               
        }
    leveleulertoor.push_back(level[s]);
        eulertoor.push_back(s);
    
	
						
}
 
 


void build(ll pos,ll start,ll end)
{
	//cout<<pos<<" "<<start<<" "<<end<<endl;
	if(start==end)
		{
			Tree[pos]=leveleulertoor[end];
			
		}	
	else
	{
		ll mid=(start+end)/2;
		build(2*pos+1,start,mid);
		build(2*pos+2,mid+1,end);
		Tree[pos]=min(Tree[2*pos+1],Tree[2*pos+2]);
	}
	
}

void update (ll pos,ll start,ll end,ll idx,ll val)
{
	if(start==end)
	{
		leveleulertoor[start]=val;
		Tree[pos]=leveleulertoor[start];	
	}
	else
	{
		ll mid=(start+end)/2;
		if(start<=idx and idx<=mid)
			update(2*pos+1,start,mid,idx,val);
		else
			update(2*pos+2,mid+1,end,idx,val);
		Tree[pos]=min(Tree[2*pos+1],Tree[2*pos+2]);
	}
	
}

ll query(ll pos,ll start,ll end,ll l,ll r)
{
	//cout<<start<<" "<<end<<" "<<l<<" "<<r<<endl;
	if(r<start or end<l)
		return LLONG_MAX;
	if(l<=start and end<=r)
		return Tree[pos];
	ll mid=(start+end)/2;
	ll x=query(2*pos+1,start,mid,l,r);
	ll y=query(2*pos+2,mid+1,end,l,r);
	//cout<<"xxyy"<<x<<" "<<y<<endl;
	return min(x,y);

}










int main()
{
	ll t,x,k,n,q;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cerr.tie(0);
   scanf("%lld",&t);
	for(ll l=1;l<=t;l++)
	{
		for(ll i=0;i<=1000;i++)
		{
			v[i].clear();
			papa[i]=0;
			level[i]=0;
			visited[i]=0;
		}
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			while(k--)
			{
				scanf("%lld",&x);
				v[i].push_back(x);
			}
		}
		bfs(1);
		section=sqrt(height+1);
		memset(visited,0,sizeof(visited));
		//cout<<section<<endl;
		dfs(1);
		/*for(ll i=1;i<=n;i++)
			cout<<p[i]<<" ";
		cout<<endl;*/
		
		scanf("%lld",&q);
		ll u,v;
		cout<<"Case "<<l<<":"<<endl;
		while(q--)
		{

			scanf("%lld%lld",&u,&v);
			cout<<query(u,v)<<endl;
		}

	}
}