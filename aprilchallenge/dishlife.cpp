#include <bits/stdc++.h>
#define ll long long int
using namespace std;
set<ll> st[1000010];
ll hash[1000010];
vector<pair<ll,ll> >  v;


bool comp(pair<ll,ll> a , pair<ll,ll> b)
{
	return a.second>b.second;
}
int main()
{
	ll t,k,a,b,temp,s;
	scanf("%lld",&t);
	while(t--)
	{

		scanf("%lld%lld",&a,&s);
		//cout<<"a"<<a<<" "<<s;
		v.clear();
		for(ll i=0;i<=a;i++)
		{
			hash[i]=0;
			st[i].clear();
		}
		for(ll i=0;i<a;i++)
		{
			scanf("%lld",&k);
			while(k--)
			{
				scanf("%lld",&temp);
				st[i].insert(temp);
			}
			v.push_back(make_pair(i,st[i].size()));

		}
		set<ll> stemp;
		sort(v.begin(),v.end(),comp);
		set<ll> :: iterator i;
		ll prevs=0,cnt=0;
		ll flag=0;
		for(ll j=0;j<v.size();j++)
		{

			for(i=st[v[j].first].begin();i!=st[v[j].first].end();i++)
				stemp.insert(*i);
			//cout<<endl;
			if(stemp.size()>prevs)
			{
				prevs=stemp.size();
				cnt++;
				if(stemp.size()==s)
				{
					flag=1;
					//cout<<"kg"<<j<<" "<<cnt<<" "<<s<<endl;
					break;
				}

			}
		}
		//cout<<"kella  "<<cnt<<" "<<a<<" "<<s<<endl;
		if(cnt<a && flag==1)
			cout<<"some"<<endl;
		else if(flag==0)
			cout<<"sad"<<endl;
		else
			cout<<"all"<<endl;
		

	}
}