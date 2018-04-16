#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
ll par[100002];
ll sz[100002];
ll findp(ll p)
{
	if(p==par[p])
		return p;
	else
		return findp(par[p]);
}
void uni(char a, char b)
{
	ll aa=findp(a-97);
	ll bb=findp(b-97);

	if(sz[aa]>=sz[bb])
	{
		sz[aa]+=sz[bb];
		par[bb]=aa;
	}
	else
	{
		sz[bb]+=sz[aa];
		par[aa]=bb;
	}
}



int main()
{

	string s1,s2;
	ll n;
	cin>>n;
	cin>>s1>>s2;
	for(ll i=0;i<=25;i++)
	{
		sz[i]=1;
		par[i]=i;
	}
	
	vector<pair<char,char> > vp;
 	for(ll i=0;i<n;i++)
	{
		ll roota=findp(s1[i]-97);
		ll rootb=findp(s2[i]-97);
		// cout<<roota<<" "<<rootb<<endl;
		if(roota!=rootb)
		{
			uni(s1[i],s2[i]);
			vp.push_back(make_pair(s1[i],s2[i]));

			
		}
	}
	cout<<vp.size()<<endl;
	for(ll i=0;i<vp.size();i++)
	{
		cout<<vp[i].first<<" "<<vp[i].second<<endl;
	}


}