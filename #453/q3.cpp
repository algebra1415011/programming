#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
int main()
{


	ll a,b;
	cin>>a>>b;
	ll lena=log10(a)+1;
	ll lenb=log10(b)+1;
	// cout<<lena<<" "<<lenb<<endl;
	vector<ll> v;

	while(a)
	{
		v.push_back(a%10);
		a/=10;
	}
	sort(v.begin(),v.end());

	if(lena<lenb)
	{
		
		for(ll i=v.size()-1;i>=0;i--)
		{
			cout<<v[i];
		}
		cout<<endl;
		exit(0);
	}
	vector<ll> vb;
	while(b)
	{
		vb.push_back(b%10);
		b/=10;
	}
	
	ll maxi=0;
	ll len=vb.size()-1;
	if(v[v.size()-1])
	for(ll i=v.size()-1;i>=0;i--)
	{
		cout<<v[i]<<" "<<vb[len]<<endl;
			if(v[i]>vb[len] )
			{
				ll aa=v[i];
				ll bb=vb[len];
				if((i-1)>=0 )
					{

						 // cout<<"h"<<v[i]<<" "<<v[i-1]<<endl;
						ll temp=v[i];
						v[i]=v[i-1];
						v[i-1]=temp;
						// cout<<"a"<<aa<<" "<<bb<<endl;

						
					}
				if(aa>bb)
				{
					break;
				}	

			}
			len--;

	}
	for(ll i=v.size()-1;i>=0;i--)
		{
			cout<<v[i];
		}
		cout<<endl;
		exit(0);




}