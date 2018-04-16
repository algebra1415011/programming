#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[10000];
int main()
{

	ll t;
	cin>>t;
	string s;
	while(t--)
	{
		for(ll i=0;i<=200;i++)
			arr[i]=0;
		cin>>s;
		ll sn=0;
		ll m=0;
		for(ll i=0;i<s.length();i++)
		{
			if(s[i]=='m')
			{
				if(i-1>=0 and s[i-1]=='s' and arr[i-1]==0)
					arr[i-1]=1;
				else if(i+1<s.length() and s[i+1]=='s' and arr[i+1]==0)
					arr[i+1]=1;
			}
			
			
		}
		for(ll i=0;i<s.length();i++)
			{
				if(arr[i]==0)
				{
					if(s[i]=='m')
						m++;
					if(s[i]=='s')
						sn++;
				}
			}
		if(sn==m)
				cout<<"tie"<<endl;
			else if(sn>m)
				cout<<"snakes"<<endl;
			else 
				cout<<"mongooses"<<endl;

	}
	
}