#include <bits/stdc++.h>
using namespace std ;
#define ft first
#define sd second
#define pb push_back
#define ll long long int
#define mp make_pair
#define loop(i, a, b) for(i=a; i<b; i++)
const int mod = 1e9 + 7;
const ll INF = 1e17;
 
ll power(ll x,ll y){
  ll t=1;
  while(y>0){
    if(y%2) y-=1,t=t*x%mod;
    else y/=2,x=x*x%mod;
  }
  return t;
}
 
ll inverse(ll q)
{
    ll t;
    t=power(q,mod-2);
    return t;
}
 
bool cmp(pair<ll,ll>p1,pair<ll,ll>p2){
    if(p1.ft>p2.ft){
        return true;
    }
    else if(p1.ft==p2.ft){
        if(p1.sd<=p2.sd){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
 
string numtostr(ll n){
    stringstream ss;
    ss << n;
    string str = ss.str();
    return str;
}
ll strtonum(string s){
    ll ans=0,i;
    loop(i,0,s.length()){
        ll temp=s[i]-'0';
        ans*=10;
        ans+=temp;
    }
    return ans;
}
vector<ll> v[300001];
ll n,k,q,he=-1;
ll a[300001],par[300001];
pair<ll,ll> sto[300001];
ll modulo(ll a,ll b){
    ll ans=1;
    while(b){
        if(b%2){
            ans*=a;
            ans%=k;
        }
        a*=a;
        a%=k;
        b/=2;
    }
    return ans;
}
void dfs(ll x, ll h){
    he=max(he,h);
    ll i;
    loop(i,0,v[x].size()){
        dfs(v[x][i],h+1);
    }
}
void init(ll x,ll h){
    ll i;
    loop(i,0,v[x].size()){
        ll temp=((a[v[x][i]]%k)*modulo(10,h-1))%k;
        sto[v[x][i]].ft=(sto[x].ft+temp)%k;
        sto[v[x][i]].sd=h-1;
        init(v[x][i],h-1);
    }
}
int main(){
    ll i,j,l,x,y;
    cin>>n>>k>>q;
    loop(i,1,n+1){
        cin>>a[i];
    }
    loop(i,1,n){
        cin>>x;
        par[i+1]=x;
        v[x].pb(i+1);
    }
    dfs(1LL,0LL);
    sto[1].ft=((a[1]%k)*(modulo(10,he)))%k;
    sto[1].sd=he;
    init(1LL,he);
    while(q--){
        cin>>x>>y;
        if(x==1){
            if(sto[y].ft%k==0){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else{
            if(sto[y].sd==0){
                ll temp=(sto[y].ft-sto[par[x]].ft+k)%k;
                if(temp==0){
                    cout<<"YES"<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
            }
            else{
                ll den=modulo(modulo(10,sto[y].sd),k-2)%k;
                ll temp=((sto[y].ft*den)%k-(sto[par[x]].ft*den)%k+k)%k;
                if(temp==0){
                    cout<<"YES"<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
            }
        }
    }
return 0;
 
}
 