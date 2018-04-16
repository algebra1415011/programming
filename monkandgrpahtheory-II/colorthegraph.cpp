#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> v[1000010];
ll color[1000010];
ll visit[1000010];
ll arr[3];
ll flag=0;
void dfs(ll s)
{
	visit[s]=1;
	if(!color[s])
		{
			color[s]=1;
			arr[1]++;
		}	
	for(ll i=0;i<v[s].size();i++)
	{
		if(!visit[v[s][i]])
		{
			if(color[s]==1)
			{
				color[v[s][i]]=2;
				arr[2]++;
			}
			else
			{
				color[v[s][i]]=1;
				arr[1]++;
			}
			dfs(v[s][i]);
		}
	}
}

int main(int argc, char const *argv[])
{
	ll t,n,m,a,b;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		flag=0;
		memset(color,0,sizeof(color));
		memset(visit,0,sizeof(visit));
		for(ll i=1;i<=n;i++)
			v[i].clear();
		for(ll i=0;i<m;i++)
		{
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		
		ll sum=0;
		for(ll i=1;i<=n;i++)
		{
			if(!visit[i])
			{
				dfs(i);
				
				sum=sum+max(arr[1],arr[2]);
				//cout<<arr[1]<<" "<<arr[2]<<endl;
				arr[1]=0;
				arr[2]=0;
			}
		}
		for(ll i=1;i<=n;i++)
		{	
				for(ll j=0;j<v[i].size();j++)
					{
							if(color[i]==color[v[i][j]])
							{
								cout<<"NO"<<endl;
								flag=1;
								break;
							}
					}
						if(flag==1)
							break;
					}
						
		if(flag!=1)
			cout<<sum<<endl;
		flag=0;
	}
	return 0;
}