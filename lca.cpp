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
			if(!visited[v[current][i]])
			{
				level[v[current][i]]=level[current]+1;
				height=max(height,level[v[current][i]]);
				visited[v[current][i]]=1;
				papa[v[current][i]]=current;
				q.push(v[current][i]);
			}
		}
	}
}

void dfs(ll s)
{

	//cout<<s<<" ";
	if(level[s]<section)
		p[s]=1;
	else if(!(level[s]%section))
		p[s]=papa[s];
	else
		p[s]=p[papa[s]];


	visited[s]=1;
	for(ll i=0;i<v[s].size();i++)
	{
		if(!visited[v[s][i]])
			dfs(v[s][i]);
	}
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
			x=papa[x];
		else
			y=papa[y];
	}	
	return x;
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