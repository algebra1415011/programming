#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ll arr[n];
		set<ll> current,ans;
		for(ll i=0;i<n;i++)
		{
			set<ll> newdata;
			cin>>arr[i];
			current.insert(arr[i]);
			set<ll> :: iterator it;
			//cout<<"l"<<endl;
			for(it=current.begin();it!=current.end();it++)
				{
					//cout<<"a"<<*it<<" ";
					newdata.insert((*it)&arr[i]);
				}	
			for(it=newdata.begin();it!=newdata.end();it++)
				ans.insert((*it)&arr[i]);
			current=newdata;
			//cout<<endl;


		}
		cout<<ans.size()<<endl;
	}


	return 0;
}