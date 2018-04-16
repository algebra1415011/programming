#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
ll mp[26];
 int main()
 {
 	string s;
 	cin>>s;
 	string s1,s2;
 	for(ll i=0;i<s.length();i++)
 	{
 		mp[s[i]-'a']++;
 	}
 	ll cnt=0;
 	for(ll i=0;i<=25;i++)
 	{
 		if(mp[i])
 			cnt++;
 	}
 	if(cnt>=5 || cnt==1)
 	{
 		cout<<"No"<<endl;
 		return 0;
 	}
 	if(cnt==2)
 	{
 		for(ll i=0;i<26;i++)
 		{
 			if(mp[i]==1)
 			{
 				cout<<"No"<<endl;
 				return 0;
 			}
 		}
 	}
 	if(cnt==3)
 	{
 		ll cnt1=0;
 		for(ll i=0;i<26;i++)
 		{
 			if(mp[i]==1)
 			{
 				cnt1++;
 			}
 		}
 		if(cnt1==3)
 		{
 			cout<<"No"<<endl;
 			return 0;
 		}
 	}
 	cout<<"Yes"<<endl;

 	

 	return 0;
 }