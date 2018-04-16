#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
int main()
{

	ll t;
	cin>>t;
	string s;
	while(t--)
	{
		cin>>s;
		ll arr[100010]={0};
		ll c=1;
		ll len=s.length();
		for(ll i=0;i<len;i++)
		{
			if(s[i]=='1')
			{
				arr[i+1]=c;
				c++;
			}
		}
		
		c=0;
		ll sum=0;
		ll prev=0;
		for(ll i=1;i<=len;i++)
		{
			if(arr[i]>0)
			{
				if(prev==0)
				{
					prev=i;
					continue;
				}	
				else if(i-prev>=2)
				{
					sum=sum+(i-prev)*arr[prev];
					//cout<<i-prev<<" "<<arr[prev]<<endl;
					prev=i;
				}
				else 
				prev=i;	
			}
		}

		if(len+1-prev>=2)
		{
			sum=sum+(len+1-prev)*arr[prev];
		}	
		cout<<sum<<endl;
	}
}