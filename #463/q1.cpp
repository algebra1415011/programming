#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
int main()
{

	ios_base::sync_with_stdio(0);
	ll n;
	cin>>n;
	string str;
	cin>>str;
	string s;
	s=""+str[0];
	vector<char> v;
	v.push_back(str[0]);
	for(ll i=1;i<str.length();i++)
	{
		// cout<<str[i];
		if(str[i]=='a' or str[i]=='e' or str[i]=='o' or str[i]=='i' or str[i]=='y' or str[i]=='u')
		{
			if(str[i-1]=='a' or str[i-1]=='e' or str[i-1]=='o' or str[i-1]=='i' or str[i-1]=='y' or str[i-1]=='u')
				continue;


		}
		v.push_back(str[i]);
	}
	for(ll i=0;i<v.size();i++)
	{
		 cout<<v[i];
	}
	cout<<endl;



	return 0;
}