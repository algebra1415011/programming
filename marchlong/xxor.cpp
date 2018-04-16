#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
ll mat[100001][100][2];
ll arr[1000000];
int main()
{
	ll n,q;
	cin>>n>>q;
	ll c0=0,c1=0;
	ll len=0;
	ll l,r;
	ll maxi=0;
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
		ll x=arr[i];
		c0=0;
		c1=0;
		len=0;
		while(x)
		{
			if(x%2==0)
				mat[i][len][0]++;
			else
				mat[i][len][1]++;
			x/=2;
			

			len++;
			
		}
		// cout<<"len"<<len<<endl;
		maxi=max(maxi,len);
		for(ll j=0;j<=31;j++)
			{
				if(i>=1)
				{
					mat[i][j][0]+=mat[i-1][j][0];
				    mat[i][j][1]+=mat[i-1][j][1];
				}
			}
	}

	ll ans=0;
	
	for(ll i=0;i<q;i++)
	{
		cin>>l>>r;
		l--;
		r--;
		ans=0;
		string temp;
		ll val=1;
		//cout<<endl;
		for(ll j=0;j<=30;j++)
		{
			ll zeros,ones;
			if(l>=1)
				zeros=mat[r][j][0]-mat[l-1][j][0];
			if(l>=1)
			 ones=mat[r][j][1]-mat[l-1][j][1];
			if(l==0)
				zeros=mat[r][j][0];
			if(l==0)
			    ones=mat[r][j][1];
			zeros=(r-l+1)-ones;
			//cout<<ones<<zeros<<" ";
			if(zeros>=ones)
			{
				ans+=val;
			}
			val*=2;

			// cout<<ans<<endl;
			
		}
		cout<<ans<<endl;	
	}
	return 0;
}