#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
vector<pair<ll,ll> > input;

ll n;

bool collinear(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3)
{
	return ((y2-y1)*(x2-x3))==((x2-x1)*(y2-y3));
}

bool solve(ll a,ll b)
{
	ll x1=input[a].first;
	ll x2=input[b].first;
	ll y1=input[a].second;
	ll y2=input[b].second;
	vector<pair<ll,ll> > notcollinear;
	for(ll i=0;i<n;i++)
	{
		if(i==a or i==b)
			continue;
		if(!collinear(x1,y1,x2,y2,input[i].first,input[i].second))
			notcollinear.push_back(make_pair(input[i].first,input[i].second));
	}
	if(notcollinear.size()<=2)
		return true;
	x1=notcollinear[0].first;
	x2=notcollinear[1].first;
	y1=notcollinear[0].second;
	y2=notcollinear[1].second;
	for(ll j=2;j<notcollinear.size();j++)
	{
			if(!collinear(x1,y1,x2,y2,notcollinear[j].first,notcollinear[j].second))
				return false;
	}	
	return true;
	
}


int main()
{

	
	cin>>n;
	ll a,b;
	for(ll i=0;i<n;i++)
	{
		cin>>a>>b;
		input.push_back(make_pair(a,b));
	}

	if(input.size()<=3)
	{
		cout<<"YES"<<endl;
		exit(0);
	}

	if(solve(0,1) or solve(1,2) or solve(0,2))
	{
		cout<<"YES"<<endl;
		exit(0);
	}
	else
	{
		cout<<"NO"<<endl;
		exit(0);
	}

	return 0;
}