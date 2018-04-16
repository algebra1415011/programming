#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll n;
	cin>>n;
	double x[n];
	double v[n];
	for(ll i=0;i<n;i++)
		cin>>x[i];
	for(ll i=0;i<n;i++)
		cin>>v[i];
	double start=0,mid;
	double end=10000000000;
	
	ll count=0;
	double ans=10000000000;
	while(end-start>0.0000001)
	{
		count++;
		double l=-1e18;
		double r=1e18;
		mid=(start+end)/2;
		for(ll i=0;i<n;i++)
		{
			l=max(l,x[i]-mid*v[i]);
			r=min(r,x[i]+mid*v[i]);
		}
		if(l<=r)
			{
				//ans=min(ans,mid);
				end=mid;

			}	
		else
				start=mid;
		
		//cout<<mid<<" "<<end<<endl;
		
	}
	printf("%.7f\n",mid);

	
	return 0;
}