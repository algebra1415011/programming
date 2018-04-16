#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{

	ll t;
	cin>>t;
	string s;
	map<string,int> mp;
	while(t--)
	{
		cin>>s;
		if(mp[s])
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		mp[s]=1;
	}
	return 0;
}