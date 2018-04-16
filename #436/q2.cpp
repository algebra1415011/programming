#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
	ll n;
	string s;
	cin>>n;
	cin>>s;
	ll flag=1;
	set<char> st;
	ll ii=0;
	ll maxi=0;

	for(ll i=0;i<n;i++)
	{
			if(isupper(s[i]))
			{
				if(flag)
				flag=0;
				else
				flag=1;


			}
			if(flag==1)
			{
				if(islower(s[i]))
					st.insert(s[i]);
			}
			else
			{
				ll sz=st.size();
				maxi=max(sz,maxi);
				st.clear();
				flag=1;
			}
	}
	ll sz=st.size();
			maxi=max(sz,maxi);

	cout<<maxi<<endl;
	return 0;
}