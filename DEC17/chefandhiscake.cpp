#include <bits/stdc++.h>
#define  ll long long int
using namespace std;


int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		ll mat[n][m];
		ll pat[n][m];
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<m;j++)
			{
				pat[i][j]=0;

			}
		}
		ll pp=0;
		for(ll i=1;i<n;i++)
		{
			pp=0;
			for(ll j=0;j<m;j++)
			{
				cin>>mat[i][j];
				if(i!=j)
					{
						
						pp=max(pp,mat[i-1][j]);

					}	


			}
			// pat[i][j]+=pp;

		}
		ll maxi=0;
		for(ll i=0;i<m;i++)
		{
			maxi=max(pat[n-1][i],maxi);
		}
		cout<<"2"<<maxi<<endl;
	}

}