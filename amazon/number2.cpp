#include<bits/stdc++.h>
#define ll long long int 
#define inf 1e18
using namespace std;

ll gcd(ll a,ll b)
{
    if(b==0)
    return a;
    else
    return (b,b%a);
}

ll lcm(ll a,ll b)
{
    return ((a*b)/__gcd(a,b));
}

ll check(ll a, ll b, ll mid,ll n)
{
    ll p=(mid/a)+(mid/b)-(mid/lcm(a,b));
    return (p>=n);
    
}


ll solve (ll a, ll b, ll n) {
  ll high=inf;
  ll start=0;
  ll ans=inf;
  while(start<=high)
  {
      ll mid=(start+high)/2;
      if(check(a,b,mid,n))
            {
                high=mid-1;
                ans=mid;
                //cout<<ans<<endl;
            }    
        
        else
        start=mid+1;
  }
  return ans;
  
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    cin >> T;
    for(ll t_i=0; t_i<T; t_i++)
    {
      ll a;
        cin >> a;
       ll b;
        cin >> b;
        ll n;
        cin >> n;

        ll out_;
        out_ = solve(a, b, n);
        cout << out_;
        cout << "\n";
    }
}