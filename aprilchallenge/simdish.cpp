#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll t;
	map<string,ll > mp;
	cin>>t;
	ll bit=0;

	ll cnt=0;
	ll to=0;
	for(ll i=0;i<t;i++)
	{
		string s;
		cnt=0;
		mp.clear();
		for(ll j=0;j<4;j++)
			{
				cin>>s;
				mp[s]++;
			}		
		for(ll j=0;j<4;j++)
		{
			cin>>s;
			if(mp[s])
				cnt++;
		}
		
		if(cnt>=2)
			cout<<"similar"<<endl;
		else
			cout<<"dissimilar"<<endl;


	}
}