#include <bits/stdc++.h>
#define ll long long int 
#define inf 1e18+1
using namespace std;
ll dp[10000001];


ll Tree[10000001];



void update (ll pos,ll start,ll end,ll idx,ll val)
{
	//cout<<start<<" "<<pos<<" "<<end<<" "<<val<<endl;
	if(start==end)
	{
		// cout<<"up"<<start<<" "<<pos<<" "<<end<<" "<<val<<endl;
		Tree[pos]=val;	
	}
	else
	{
		ll mid=(start+end)/2;
		if(start<=idx and idx<=mid)
			update(2*pos+1,start,mid,idx,val);
		else
			update(2*pos+2,mid+1,end,idx,val);
		Tree[pos]=min(Tree[2*pos+1],Tree[2*pos+2]);
	}
	
}

ll query(ll pos,ll start,ll end,ll l,ll r)
{
	 // cout<<"start"<<start<<" "<<end<<endl;
	if(r<start or end<l)
		return inf;
	if(l<=start and end<=r)
		{
			// cout<<"pos"<<pos<<endl;
			return Tree[pos];

		}	
	ll mid=(start+end)/2;
	ll x=query(2*pos+1,start,mid,l,r);
	ll y=query(2*pos+2,mid+1,end,l,r);
	// cout<<"xy"<<x<<" "<<y<<" "<<2*pos+2<<endl;
	return min(x,y);

}


int main()
{

	ll n,m,k;
	ll ans=0;
	ll flag=0;
	scanf("%lld%lld",&n,&m);
	ll L[n],price[n],cap[n],preL[n];
	preL[0]=0;
	for(ll i=1;i<n;i++)
		{
			scanf("%lld",&L[i]);
			preL[i]=preL[i-1]+L[i];
		}
		preL[n]=inf;	
	for(ll i=1;i<n;i++)
		scanf("%lld",&cap[i]);
	for(ll i=1;i<n;i++)
		scanf("%lld",&price[i]);
	memset(Tree,inf,sizeof(Tree));
	memset(dp,inf,sizeof(dp));
	
	dp[n]=0;
	update(0,0,n,n,0);
	for(ll i=n-1;i>=1;i--)
	{
		ll ind=lower_bound(preL+1,preL+n,preL[i-1]+cap[i])-preL;
		  // cout<<preL[ind]<<" k"<<preL[i-1]+cap[i]<<" "<<ind<<endl;
		
		if(ind==n)
			dp[i]=price[i];
		else
		{ 
			if(preL[ind]==(preL[i-1]+cap[i]))
						ind++;
			
			// cout<<"kella"<<query(0,0,n-1,i+1,ind)<<" "<<i+1<<" "<<ind<<endl;
			dp[i]=price[i]+query(0,0,n,i+1,ind);
			// cout<<" "<<dp[i]<<endl;
		}	
		 // cout<<"dp"<<i<<" "<<dp[i]<<endl;	
		update(0,0,n,i,dp[i]);
	}
	//cout<<"hello"<<endl;
	for(ll i=0;i<m;i++)
	{
		scanf("%lld",&k);
		ll ind=lower_bound(preL+1,preL+n,k)-preL;

		
		if(ind==n)
			cout<<0<<endl;

		else
		{
			
			//cout<<"k"<<ind<<endl;
			if(preL[ind]==k)
				ind++;

			ll val=query(0,0,n,1,ind);
			if(val==inf)
				cout<<"-1"<<endl;
			else
				cout<<val<<endl;
		}
		// cout<<endl;
	}

}