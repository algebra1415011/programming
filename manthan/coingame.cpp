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
		ll count=0;
		for(ll i=0;i<n;i++)
		{
			cin>>arr[i];
			while(arr[i]%2==0)
			{
				count++;
				arr[i]/=2;
			}
		}
		if(count%2==0)
			cout<<"Alan"<<endl;
		else
			cout<<"Charlie"<<endl;
	}
	return 0;
}