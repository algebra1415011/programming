#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n;
ll visited[100009];
vector<ll> v[100009];
ll BIT[100009];
void update(int x, int delta)       //add "delta" at index "x"
{
    for(; x <= n; x += x&-x)
          BIT[x] += delta;
}
int query(int x)      //returns the sum of first x elements in given array a[]
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
         sum += BIT[x];
     return sum;
}

void dfs(ll s,ll l,ll x)
{
    visited[s]=1;
    update(s,x);
    if(s==l)
        return;
    for(ll i=0;i<v[s].size();i++)
        if(!visited[v[s][i]])
            dfs(s,l,x);
}

int main(int argc, char const *argv[])
{
    ll m,a,b,l,r,x,k;
    cin>>n>>m;
    for(ll i=1;i<=n-1;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);

    }
    for(ll i=1;i<=n;i++)
    {
        cin>>k;
        update(i,k);
    }


    for(ll i=0;i<m;i++)
    {
        cin>>l>>r>>x;
        dfs(l,r,x);
    }

    for(ll i=1;i<=n;i++)
    {
        cout<<query(i)-query(i-1)<<" ";
    }
    cout<<endl;
    return 0;
}