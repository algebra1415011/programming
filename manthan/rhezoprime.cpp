#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> v;
ll p[5001]={0};
ll res[50005];
ll dp[50005];
ll pre[50005];
int main()
{
	ll n;
	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++)
		{
			cin>>arr[i];
			if(i>=1)
				pre[i]=arr[i]+pre[i-1];
			else
				pre[i]=arr[i];
			// cout<<pre[i]<<" ";
		}	

	memset(p,0,sizeof(p));
    p[0]=1;
    p[1]=1;
    for(ll i=2;i<5001;i++){
        if(p[i]==0){
            for(ll j=2*i;j<5001;j+=i)
            {
                p[j]=1;
            }
        }
    }
     ll temp=1;
    for(ll i=2;i<5001;i++){
        if(p[i]==0){
            v.push_back(i);
        }
       
    }
    ll maxi=0;
    for(ll i=2;i<=n;i++)
    {

	    for(ll j=0;j<v.size() and v[j]<=i;j++)
			{
				// cout<<v[j]<<" ";
				if(i==v[j])
					dp[i]=max(dp[i],pre[i-1]);
				else
					dp[i]=max(dp[i],pre[i-1]-pre[i-v[j]-1]+dp[i-v[j]-1]);
			}
	// cout<<dp[i]<<" ";		
	maxi=max(dp[i],maxi);				
	}	
	cout<<maxi<<endl;	




	return 0;
}