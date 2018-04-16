#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
int main()
{
	ll n;
	cin>>n;
	string s;
	cin>>s;
	for(ll i=1;i<n-1;i++)
	{
		if(s[i-1]==s[i] and s[i]!='?')
		{
			cout<<"No"<<endl;
			return 0;
		}
	}
	if(s[0]=='?' | s[n-1]=='?')
	{
		cout<<"Yes"<<endl;
		return 0;
	}

	for(ll i=1;i<n-1;i++)
	{
		if(s[i]=='?')
		{
			if(s[i-1]==s[i+1])
			{
				cout<<"Yes"<<endl;
				return 0;
			}
			if(s[i+1]=='?')
			{
				if(i+2<n and s[i-1]==s[i+2])
				{
					cout<<"Yes"<<endl;
					return 0;
				}

			}


		}
		
	}

	cout<<"No"<<endl;
	return 0;


	
}