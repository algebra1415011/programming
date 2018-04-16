#include <bits/stdc++.h> 
using namespace std ;
#define ll long long int
#define inf 1000000000000LL
#define m 1000000006
#define MOD 1000000007
ll fibo(ll n){
  if(n==0){
    return 0; 
  }
 ll e=n-2;
 
   ll a=0,b=1,c=1,d=1; 
   ll a1,b1,c1,d1,a2=0,b2=1,c2=1,d2=1;  
  while(e>0){
       if(e%2==1){
           a1= (a*a2+b*c2)%m;
           c1= (c*a2+d*c2)%m;
           b1= (a*b2+ b*d2)%m;
           d1= (b2*c+ d*d2)%m;
           a=a1;
           b=b1;
           c=c1;
           d= d1;
       }
           a1= (a2*a2+b2*c2)%m;
           c1= (c2*a2+d2*c2)%m;
           b1= (a2*b2+ b2*d2)%m;
           d1= (b2*c2+ d2*d2)%m;
           a2=a1;
           b2=b1;
           c2=c1;
           d2= d1;
           e= e/2;
      
  }
    return d%m;
}
 
long long int fastpow( long long int w, long long int e)
{
 long long int a,b,ans=1;
    a=w%MOD;
    b=e%m;
    while(b>0)
    {
        if(b%2==1)
        {
           ans=(ans*a)%MOD;
        }
        a= (a*a)%MOD;
        b=b/2;
    }
    return ans%MOD;
}
 
int main()
{
 
   // cout<<fibo(0)<<" "<<fibo(1)<<" "<<fibo(3);
   ll t;
   cin>>t;
   while(t--){
    ll x,y,n;
    cin>>x>>y>>n;
 
     ll ans= fastpow(x+1, fibo(n-1));
     ans= (ans*fastpow(y+1,fibo(n)))%MOD;
    ans= (MOD-1+ans)%MOD;
    cout<<ans<<endl;
   }
  
return 0;
}