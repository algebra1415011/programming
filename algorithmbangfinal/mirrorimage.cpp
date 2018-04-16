#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector< ll> v[1000010];
vector<ll> lev[1000010];
ll level[1000010];
ll visit[1000010];
void bfs()
{
	queue<ll> qu;
	qu.push(0);
	level[0]=0;
	visit[0]=1;
	lev[level[0]].push_back(0);
	while(!qu.empty())
	{
		ll current=qu.front();
		//cout<<current+1<<endl;
		qu.pop();
		for(ll i=0;i<v[current].size();i++)
		{
			//cout<<"c"<<v[current][i]<<endl;
			if(!visit[v[current][i]] || v[current][i]==-2)
			{
				visit[v[current][i]]=1;
				qu.push(v[current][i]);
				level[v[current][i]]=level[current]+1;
				lev[level[v[current][i]]].push_back(v[current][i]);
			}
		}
	}
}


int main()
{

	ll n,m,a,b;
	char c;
	cin>>n>>m;
	for(ll i=0;i<n;i++)
	{
		v[i].push_back(-2);
		v[i].push_back(-2);
	}

	for(ll i=0;i<n-1;i++)
	{
		cin>>a>>b>>c;a--,b--;
		if(c=='L')
		v[a][0]=b;
		else if(c=='R')
		v[a][1]=b;
	}
	
	/*for(ll i=0;i<n;i++)
	{
		cout<<i<<" "<<v[i][0]<<" "<<v[i][1]<<endl;
	}*/
	ll k;
	bfs();
	for(ll i=0;i<m;i++)

	{
		cin>>k;
		ll ind=0;
		//cout<<"k to find "<<k<<endl;
		k--;
		for(ll j=0;j<lev[level[k]].size();j++)
			{
				//cout<<lev[level[k]][j]+1<<" ";
				if(lev[level[k]][j]==k)
				{
					ind=j;
					break;
				}
			}
		ll l=-1;	
		ll ans=1;
		for(ll j=lev[level[k]].size()-1;j>=0;j--)
		{
			l++;
			if(l==ind)
			{
				cout<<lev[level[k]][j]+1<<endl;
				ans=0;
				break;
			}	
		}
		if(ans)
			cout<<-1<<endl;	

	}
	
}