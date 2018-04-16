#include <bits/stdc++.h>
#define ll long long int 

using namespace std;
long long int mod=(1e9 + 7);
ll n;
ll BIT[1000010],tot[1000010],totprefix[1000010];

void update(ll index,ll res)
{
	for(ll i=index;i<=n;i+=(i&(-i)))
		BIT[i]=(BIT[i]%mod+res%mod)%mod;
}

ll query(ll index)
{
	ll sum=0;
	for(ll i=index;i>=1;i-=(i&(-i)))
		sum=(sum%mod+BIT[i]%mod)%mod;
	return sum;
}

void prec()
{
	for(ll i=0;i<=500005;i++)
		tot[i]=i;
	for(ll i=2;i<=500005;i++)
	{
		if(tot[i]==i)
		{
			//tot[i]=i-1;
			for(ll j=i;j<=500005;j=j+i)
				tot[j]-=tot[j]/i;

		}
	}
	
	for(ll i=1;i<=500005;i++)
	{
		for(ll j=i;j<=500005;j=j+i)
		{
			totprefix[j]+=(i*tot[j/i]);
		}
	}
	/*for(ll i=1;i<=100;i++)
		cout<<"i"<<i<<" "<<totprefix[i]<<" ";*/
}
ll arr[1000010];
int main()
{
	prec();
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		cin>>arr[i];
		update(i,totprefix[arr[i]]);
	}
	ll q,a,b;
	char c;
	scanf("%lld",&q);
	for(ll i=0;i<q;i++)
	{
		cin>>c;

		if(c=='C')
		{
			cin>>a>>b;
			cout<<(mod+query(b)-query(a-1))%mod<<endl;
			
		}
		else
		{
			cin>>a>>b;
			arr[a]=b;
			update(a,-BIT[a]+totprefix[b]%mod);
			
		}	


	}

}