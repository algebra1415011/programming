#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll t,n,k;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		stack<pair<ll,ll > > st;
		map<ll,ll > ans;
		for(ll i=0;i<n;i++)
		{
			scanf("%lld",&k);
			if(i==0)
				{
					st.push(make_pair(k,i));
					ans[i]=1;
				}	
			else
			{
				while(!st.empty() && k>=st.top().first)
					st.pop();
				if(st.empty())
					ans[i]=i+1;
				else
					ans[i]=i-st.top().second;
			}
			st.push(make_pair(k,i));
		}
		for(ll i=0;i<n;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
}