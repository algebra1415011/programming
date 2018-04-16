#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll hash1[1001],hash2[1001];
int main()
{
	ll n,k,p;
	cin>>n;
	//ll hash1[1001];
	for(ll i=0;i<n;i++)
	{
		cin>>k;

		for(ll j=0;j<k;j++)
		{
			cin>>p;
			hash1[p]++;
		}
		for(ll j=1;j<=1000;j++)
			if(hash1[j]>=1)
				hash2[j]++;
		memset(hash1,0,sizeof(hash1));	

	}
	ll flag=0;
	for(ll i=1;i<=1000;i++)
		{
			if(hash2[i]>=n)
			{
				flag=1;
				cout<<i<<" ";

			}	

	}
	
	if(flag)
	cout<<"-1"<<endl;	

	return 0;

}