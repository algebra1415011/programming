#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

ll Tree[1000010];
ll arr[1000010];


ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    else 
    return gcd(b,a%b);
}

void build(ll pos,ll start,ll end)
{
	//cout<<pos<<" "<<start<<" "<<end<<endl;
	if(start==end)
		Tree[pos]=arr[end];
	else
	{
		ll mid=(start+end)/2;
		build(2*pos+1,start,mid);
		build(2*pos+2,mid+1,end);
		Tree[pos]=gcd(Tree[2*pos+1],Tree[2*pos+2]);
	}
	
}



ll query(ll pos,ll start,ll end,ll l,ll r)
{
	//cout<<start<<" "<<endl<<endl;
	if(r<start or end<l)
		return 0;
	if(l<=start and end<=r)
		return Tree[pos];
	ll mid=(start+end)/2;
	ll x=query(2*pos+1,start,mid,l,r);
	ll y=query(2*pos+2,mid+1,end,l,r);
	return gcd(x,y);

}


int powe(int a,int b)
{
    ll ans=1;
    while(b)
    
    {
        if(b%2!=0)
            ans=(ans*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return ans;
}

 
ll fibo(ll n)
{
    
    if(n==0)
        return 0;
   ll ans11=1,ans12=1,ans21=1,ans22=0,a11=1,a12=1,a21=1,a22=0,bns11=1,bns12=1,bns21=1,bns22=0;
   
   while(n)
   {
       if(n%2!=0)
       {
           a11=(ans11*bns11+ans12 *bns21)%(mod);
           a12=(ans11*bns12 +ans12 *bns22 )%(mod);
           a21=(ans21 *bns11 +ans22 *bns21 )%(mod);
           a22=(ans21 *bns12 +ans22  *bns22 )%(mod);
           ans11=a11;
           ans12=a12;
           ans21=a21;
           ans22=a22;
       }
            a11=(bns11 *bns11 +bns12 *bns21 )%(mod);
           a12=(bns11 *bns12 +bns12 *bns22 )%(mod);
           a21=(bns21 *bns11 +bns22 *bns21 )%(mod);
           a22=(bns21 *bns12 +bns22 *bns22 )%(mod);
           
           bns11=a11;
           bns12=a12;
           bns21=a21;
           bns22=a22;
           
       n/=2;
   }
   return ans22%(mod);
    
}







int main()
{
  
  ll n,q;
  cin>>n>>q;
  
  for(ll i=0;i<n;i++)
    cin>>arr[i];
  build(0,0,n-1);
  /*for(ll i=0;i<2*n-1;i++)
    cout<<Tree[i]<<" ";
  cout<<endl;
  */
  ll a,b,ans=0;
  char c;
  for(ll i=0;i<q;i++)
  {
    cin>>a>>b;
    
      ans=query(0,0,n-1,a-1,b-1);
      cout<<fibo(ans)<<endl;
    
   
  }
   
}
