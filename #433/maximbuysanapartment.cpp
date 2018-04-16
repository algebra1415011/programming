#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	int n;
	int k;
	int value=0;
	cin>>n>>k;
	if(n==k || k==0)
		cout<<0<<" "<<0<<endl;
	else
	{	
		cout<<1<<" ";
		if(n%3==0)
		{
			value=n/3;
			if(value>k)
				cout<<2*k<<endl;
			else
			{
				cout<<3*value-k<<endl;
			}
		}
		else if((n+1)%3==0)
		{
			value=(n/3)+1;
			if(value>k)
				cout<<2*k<<endl;
			else if(value==k)
				cout<<2*k-1<<endl;
			else
				cout<<3*value-1-k<<endl;

		}
		else if((n-1)%3==0)
		{
			value=n/3;
			if(value>=k)
				cout<<2*k<<endl;
			else
				cout<<3*value+1-k<<endl;
		}	

	}
}