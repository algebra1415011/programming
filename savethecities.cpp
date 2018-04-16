#include <bits/stdc++.h>
#define  ll long long int 
using namespace std;
ll check[1000001];
vector<pair<ll,ll> > prime;
int main()
{
    
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=2;i<=1000000;i++)
    {
        if(!check[i])
        {
            for(ll j=2*i;j<=1000000;j=j+i)
                check[j]=1;
        }
    }
    for(ll i=0;i<n;i++)
        {
        	cin>>arr[i];
        	
        }
    for(ll i=0;i<n;i++)
    {
    	for(ll j=i+1;j<n;j++)
    	{
    		if(!check[arr[i]+arr[j]])
    		{
    			prime.push_back(make_pair(i,j));
    		}
    	}
    } 
       

    
    cout<<endl;
    return 0;
}