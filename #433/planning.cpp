#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
    ll n,t,k;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<pair<ll,ll> > q;
    cin>>n>>k;
    ll arr[n+1];
    ll temp[n+1];
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(i<=k)
            q.push(make_pair(arr[i],i));
    }   
    for(ll i=k+1;i<=k+n;i++)
    {
        if(i<=n)
        {
            q.push(make_pair(arr[i],i));
        }

        pair<ll,ll > ptemp=q.top();
        q.pop();

        temp[ptemp.second]=i;
        ans+=(i-ptemp.second)*ptemp.first;
        //cout<<ptemp.first<<" "<<ptemp.second<<endl;


    } 
    cout<<ans<<endl;
    for(ll i=1;i<=n;i++)
        cout<<temp[i]<<" ";
    cout<<endl;
    return 0;

}