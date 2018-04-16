#include <bits/stdc++.h>
#define ll long long int
using namespace std;
bool check[10000010];
ll prime[10000010];
ll len=0;
void sieve()
 
{
	for(ll i=2;i<=100000;i++)
	{
		if(!check[i])
		{
			for(ll j=(2*i);j<=10000000;j=j+i)
				check[j]=true;
		}
	}
	ll k=0;
	for(ll i=2;i<=10000000;i++)
	{
			if(!check[i])
				prime[k++]=i;
	}
	len=k;
}
int main()
 
{
 
	sieve();
	ll t,n;
	cin>>t;
	while(t--)
	{
 
		cin>>n;
		ll k=0;
		
		stack<ll> st;
		ll res=n;
		
		set<ll> S;
		S.insert(1);
		set<ll> :: iterator it;
		
		for(ll i=0;prime[i]<len && prime[i]<=sqrt(n);i++)
		{
			//cout<<prime[i]<<" ";
			while(!(res%prime[i]))
			{
				
 
				for(it=S.begin();it!=S.end();it++)
					st.push((*it)*prime[i]);
				
				res=res/prime[i];
				while(!st.empty())
				{
					S.insert(st.top());
					st.pop();
				}
			}
			//break;
		}
		if(res>0)
		{
			for(it=S.begin();it!=S.end();it++)
					st.push((*it)*res);
				
				
				while(!st.empty())
				{
					S.insert(st.top());
					st.pop();
				}
 
		}
		S.erase(1);
		S.erase(n);
		for(it=S.begin();it!=S.end();it++)
			cout<<(*it)<<" ";
		cout<<endl;
		
	}
}