#include<bits/stdc++.h>
#define ll  long long int
using namespace std;


ll solve (ll A, ll K, ll B) {
  ll high=1e6;
  ll low=0;
  ll ans=1e18;
  ll mid;
  while(low<=high)
  {
        mid=(low+high)/2;
        ll val=K+mid*(B-A);
        // cout<<val<<" k"<<K;
        if(val>0)
        {
           
            low=mid+1;
        }
        else
        {

            high=mid-1;
        }
     // cout<<mid<<endl;   
  }
  return mid;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i=0; t_i<T; t_i++)
    {
        int A;
        cin >> A;
        int B;
        cin >> B;
        int K;
        cin >> K;
        if(B>=A)
        {
            cout<<-1<<endl;
            continue;
        }
        int out_;
        out_ = solve(A, K, B);
        cout << out_;
        cout << "\n";
    }
}