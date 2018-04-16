#include <bits/stdc++.h>
#define ll long long int
#define inf 1000000
using namespace std;
ll Tree[1000010];
ll arr[1000010];

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
		Tree[pos]=min(Tree[2*pos+1],Tree[2*pos+2]);
	}
	
}

void update (ll pos,ll start,ll end,ll idx,ll val)
{
	if(start==end)
	{
		arr[start]=val;
		Tree[pos]=arr[start];	
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
	//cout<<start<<" "<<endl<<endl;
	if(r<start or end<l)
		return INT_MAX;
	if(l<=start and end<=r)
		return Tree[pos];
	ll mid=(start+end)/2;
	ll x=query(2*pos+1,start,mid,l,r);
	ll y=query(2*pos+2,mid+1,end,l,r);
	return min(x,y);

}

int main()
{
	ll n,q;
	cin>>n>>q;
	memset(Tree,inf,sizeof(Tree));
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
		cin>>c>>a>>b;
		if(c=='q')
		{
			ans=query(0,0,n-1,a-1,b-1);
			cout<<ans<<endl;
		}
		else
		{
			update(0,0,n-1,a-1,b);
		}
	}

}

