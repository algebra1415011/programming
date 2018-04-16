#include <bits/stdc++.h>
using namespace std ;
/*
An_Tea_Love.
Never_Give_Up.
*/
#define ft first
#define sd second
#define pb push_back
#define ll long long int
#define mp make_pair
#define loop(i, a, b) for(i=a; i<b; i++)
#define run	ios_base::sync_with_stdio(0)
const int mod = 1e9 + 7;
const ll INF = 1e17;

int main(){
    run;
    ll n,m,i,j,k,l;
    cin>>n>>m;
    ll a[n][n],ans[n][n];
    ll tot=0;
    vector<pair<pair<ll,ll>,ll> >v;
    loop(i,0,n){
        loop(j,0,n){
            ll val=(i+1)*(j+1);
            v.pb(mp(mp(val,i),j));
            cin>>a[i][j];
            tot+=a[i][j];
            ans[i][j]=1;
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    tot-=(n*n);
    loop(i,0,v.size()){
        ll x=v[i].ft.sd;
        ll y=v[i].sd;
        ll req=m-ans[x][y];
        if(req<=tot){
            tot-=req;
            ans[x][y]=m;
        }
        else{
            ans[x][y]+=tot;
            tot=0;
        }
        if(tot==0){
            break;
        }
    }
    loop(i,0,n){
        loop(j,0,n){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;

}



