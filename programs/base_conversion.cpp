#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans=0;
string s;
ll cnt=0;
ll n;
int solve(int j)
{   ll temp=0;
	ll index=j;
	for(ll i=j;i>=0;i--)
	{	if(s[i]=='0')continue;
		else
		{	ll data=(int)s[i]-'0';
			data*=pow(10,j-i);
			if(temp+data<n)
			{	temp+=data;
				index=i;

			}
			else
			{	ans=ans+temp*pow(n,cnt++);
				//cout<<temp<<endl;

				return index;
			}
		}
	}
	if(temp<n)
	{	ans=ans+temp*pow(n,cnt++);
		return 0;
	}
	return  index;
}

int main()
{	cin>>n>>s;
	for(ll i=s.length()-1;i>=0;)
	{	ll idx=solve(i);
		//cout<<i<<" "<<idx<<" "<<endl;

		i=idx-1;
	}
	cout<<ans<<endl;
}
