#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{


	string s;
	cin>>s;
	
	map<char,ll> mp;
	ll cnt=0;
	for(ll i=0;i<s.length();i++)
		mp[s[i]]++;
	for(char i='a';i<='z';i++)
			if(mp[i]%2==1)
	
				cnt++;
	if(cnt!=0)
		cnt--;
	if(cnt%2==0)
		cout<<"First"<<endl;	
	else
		cout<<"Second"<<endl;



}