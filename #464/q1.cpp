#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
ll num[1000000];
ll sum1[1000000];
int main()
{

	ios_base::sync_with_stdio(0);
	ll s,f;
	ll n;
	cin>>n;
	ll arr[n+1];
	
	for(ll i=1;i<=n;i++)
	{
		cin>>arr[i];
		sum1[i]=arr[i]+sum1[i-1];

	}
	cin>>s>>f;
	ll dif=f-s;
	ll cnt=0;
	for(ll i=1;i<=n;i++)
	{
		num[i]=arr[i];
		num[i+dif+1]=-arr[i];
		if((i-dif)>=0 and (i%dif)==0)
		{
			ll value=sum1[i]-sum1[i-dif-1];
			cout<<i<<"value"<<value<<endl;
			num[i+1]=num[i]-value;
			num[i+dif-2]+=value;
		}
	}
	ll maxi=0;
	for(ll i=1;i<=n+dif+1;i++)
	{
		num[i]+=num[i-1];
		cout<<num[i]<<" ";
		if(num[i]>num[maxi])

		{
			maxi=i;
		}
	}
	

	cout<<endl;
	cout<<maxi<<endl;
	



	return 0;

}