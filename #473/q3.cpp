#include <bits/stdc++.h>
#define  ll long long int 
using namespace std;
string s;
ll n,a,b;
ll maxi=0;
void solve(ll i,ll cnt,ll flag)
{
	if(i==n)
	{
		maxi=max(cnt,maxi);
	}
	else
	{
		
		if(s[i]!='*')
		{
			cout<<s[i]<<" ";
			if(flag)
			{
				if(b>0)
				{
					b--;
					solve(i+1,cnt+1,0);
				}
				else
				{
					if(a>0 and i+2<n and s[i+2]!='*')
					{
						a--;
						solve(i+2,cnt+1,1);
					}
				}	

			}
			else
			{
				if(a>0)
				{
					a--;
					solve(i+1,cnt+1,1);
				}
				else
				{
					if(b>0 and i+2<n and s[i+2]!='*')
					{
						b--;
						solve(i+2,cnt+1,0);
					}
				}
				
			}
		}

	}
}
int main()
{

		cin>>n>>a>>b;
		cin>>s;
	solve(0,0,1);
	solve(0,0,0);
	cout<<maxi<<endl;
}