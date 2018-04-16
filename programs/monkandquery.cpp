#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> v[1000001];
ll k;
ll arr[1000001];
ll he=-1;
ll par[1000001];
pair<ll,ll> store[1000001];

ll power(ll a,ll b)
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
void height(ll src,ll h)
{
    he=max(he,h);
    for(ll i=0;i<v[src].size();i++)
            height(v[src][i],h+1);

}

void dfs(ll src,ll h)
{
    for(ll i=0;i<v[src].size();i++)
    {
        store[v[src][i]].first=(store[src].first+((arr[v[src][i]]%k)*power(10,h-1))%k)%k;
        //cout<<store[v[src][i]].first<<" "<<h-1<<endl;
        store[v[src][i]].second=h-1;
        dfs(v[src][i],h-1);
    }
}
int main()
{
    ll n,q,h,x,y;
    cin>>n>>k>>q;
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    for(ll i=2;i<=n;i++)
    {
        cin>>h;
        par[i]=h;
        v[h].push_back(i);
    }
    height(1ll,0ll);
    store[1].first=arr[1]*power(10,he);
    store[1].second=he;
    dfs(1,he);
    for(ll i=0;i<q;i++)
    {
           cin>>x>>y;
        if(x==1)
            {
                if(store[y].first%k==0)
                    cout<<"YES"<<endl;
                else
                    cout<<"NO"<<endl;
            }
        else
            {
                if(store[y].second==0)
                    {
                        ll temp=(store[y].first-store[par[x]].first+k)%k;
                        //cout<<store[y].first-store[par[x]].first<<endl;
                        if(temp==0)
                            cout<<"YES"<<endl;
                        else
                            cout<<"NO"<<endl;
                    }
                else
                    {
                        ll inverse=power(power(10,store[y].second),k-2);
                        ll temp=(store[y].first*inverse-store[x].first*inverse+k)%k;
                    //cout<<store[y].first*inverse-store[x].first*inverse<<endl;
                        if(temp==0)
                            cout<<"YES"<<endl;
                        else
                            cout<<"NO"<<endl;
                    }
            }
    }

}
