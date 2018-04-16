#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

ll fast_expoenentiation(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b%2!=0)
            ans=(ans*a)%mod;

        a=(a*a)%mod;
        b=b/2;

    }
}
int main()
{


}
