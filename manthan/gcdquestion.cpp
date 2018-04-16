#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> v[1000001];
ll visited[1000001];
ll w[1000001];
ll gcdi=0;
ll maxi=INT_MAX;
ll gcd(ll a,ll b)
{
    if(b==0)
    return a;
    else
    return gcd(b,a%b);
}

void dfs(ll s)
{
    visited[s]=1;
    gcdi=__gcd(gcdi,w[s]);
    maxi=min(gcdi,maxi);
    //cout<<maxi<<endl;
    for(ll i=0;i<v[s].size();i++)
    {
        if(!visited[v[s][i]])
        {
            dfs(v[s][i]);
        }
    }
}


int main()
{
    ll n,q,a,b;
    scanf("%lld%lld",&n,&q);
    for(ll i=0;i<n;i++)
        {
            scanf("%lld",&w[i+1]);
               
        }    
    for(ll i=0;i<q;i++)
    {
        scanf("%lld%lld",&a,&b);
        v[a].push_back(b);
       
    }
    
    for(ll i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i);
            maxi=min(maxi,gcdi);
            gcdi=0;
        }
    }
    cout<<maxi<<endl;
}