#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll visited[1000010];

int main()
{
	ios::sync_with_stdio(false);

	ll n,m,k;
	ll b,a;
	cin>>n>>m>>k;
	
	for(ll i=1;i<=m;i++)
	{
		cin>>b;
		visited[b]=1;
	}
	if(visited[1])
	{
		cout<<1<<endl;
		exit(0);
	}
	ll flag=0;
	ll mark=1;
	for(ll i=1;i<=k;i++)
	{
		cin>>a>>b;
		if(a==mark)
			mark=b;
		else if(b==mark)
			mark=a;
		if(visited[mark])
		{
			cout<<mark<<endl;
			exit(0);
		}

	}
	cout<<mark<<endl;
	return 0;
}