#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll arr[1000001];
ll f[10000010];
ll check[1000001];
void sieve()
{
	for(ll i=2;i<=1000000;i++)
	{
		//cout<<i;
			for(ll j=i;j<=1000000;j+=i)
			{
				//visited[j]=true;
				if(check[j])
					f[i]+=check[j];
			
		}
	}
	
	


}

int main()
{

	ll n;
	cin>>n;
	for(ll i=0;i<n;i++)
		{
			cin>>arr[i];
			check[arr[i]]++;
		}	
	sieve();
	ll q,k;
	cin>>q;
	for(ll i=0;i<q;i++)
	{
		cin>>k;
		cout<<f[k]<<endl;
	}

	return 0;
}