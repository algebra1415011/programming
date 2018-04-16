#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
ll pre[1000010][32]={0};
ll arr[1000010]={0};
ll power(ll a,ll  b)
{
	ll ans=1;
	while(b)
	{
		if(b%2==1)
			ans=ans*a;
		a=a*a;
		b/=2;
	}
	return ans;
}

int main()
{
	ll n,m;
	cin>>n;
	
	//ll pre[n+1][30];
	for(ll i=1;i<=n;i++)
		scanf("%lld",&arr[i]);
	scanf("%lld",&m);
	//cout<<m<<endl;
	ll key;
	for(ll i=1;i<=n;i++)
	{

		key=arr[i];

		ll j=0;
		while(key)
		{
			if(key%2==1)
				pre[i][j]=1;
			j++;
			key/=2;
		}

	}
	for(ll i=1;i<=n;i++)
		for(ll j=0;j<=31;j++)
			pre[i][j]+=pre[i-1][j];								
			/*
			0,3,2,5
			3,0,1,6
			2,1,0,7
			5,6,7,0
			*/
			
	/*for(ll i=0;i<=n;i++)
	{
		for(ll j=0;j<=31;j++)
			//cout<<pre[i][j]<<" ";
		//cout<<endl;
	}	
	*/		
	ll x1,x2,y1,y2;
	for(ll i=0;i<m;i++)
	{
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		ll ans=0;
		ll sum=0;
		for(ll j=0;j<=31;j++)
		{
			ans=(pre[x2][j]-pre[x1-1][j])*((y2-y1+1)-(pre[y2][j]-pre[y1-1][j]))+((x2-x1+1)-(pre[x2][j]-pre[x1-1][j]))*(pre[y2][j]-pre[y1-1][j]);
			//cout<<pre[x2][j]-pre[x1-1][j]<<" ";
			//cout<<pre[y2][j]-pre[y1-1][j]<<endl;

			sum=sum+ans*power(2,j);
			//cout<<j<<" "<<sum<<endl;
		}			
		printf("%lld\n",sum);
	}

}