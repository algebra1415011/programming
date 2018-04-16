#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
int main()
{

    ll n,m;
    cin>>n>>m;
    ll a[n],b[m];
    for(ll i=0;i<n;i++) 
            cin>>a[i];
    for(ll j=0;j<m;j++)
        cin>>b[j];
    ll flag=0;
    vector<ll> v;
    ll ind=0;
    for(ll i=0;i<n;i++)
    {
        flag=0;
        v.push_back(a[i]);
        for(ll j=0;j<m;j++)
        {
          
        }
       
       
            for(ll k=0;k<v.size();k++)
                cout<<v[k]<<" ";
        cout<<endl;
    }

}