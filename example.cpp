#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[1<<15][15];

ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    else
        return (b,a%b);
}
int main()
{
    ll n;
    char a='a'; 
    int  a1=a;
    int a2=float('a'+10+10.0+(float)16.3);
    cout<<a1<<" "<<a2<<endl; 
    
}