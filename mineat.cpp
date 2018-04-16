#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
ll prefix[1000000];
ll sufix[1000000];
ll ans[1000000];
ll seedha[1000000];
ll ulta[1000000];

ll uppersearch(ll arr[],ll n, ll data)
{

	ll low=0;
	ll high=n;
	ll mid;
	// cout<<data<<endl;
	while(low<=high)
	{
		 mid=(low+high)/2;
		 //cout<<mid<<endl;
		 if(arr[mid]==data)
		 	return mid-1;
		if(arr[mid]<data)
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}

	}
	return high;


}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll arr[n];
		for(ll i=0;i<=n;i++)
		{
			sufix[i]=0;
			prefix[i]=0;
			seedha[i]=0;
			ulta[i]=0;
		}
		for(ll i=0;i<n;i++)
		{
			cin>>arr[i];
			if(i==0)
				prefix[i]=arr[i];
			else
				prefix[i]+=prefix[i-1]+arr[i];
		}
		sufix[n-1]=arr[n-1];	
		for(ll i=n-2;i>=0;i--)
				{
					sufix[i]+=sufix[i+1]+arr[i];
					// cout<<sufix[i]<<" ";
				}	
		for(ll i=0;i<n;i++)
		{
			ll index=upper_bound(prefix+i+1,prefix+n,prefix[i]+arr[i])-prefix;
			// cout<<"seedha"<<" "<<index<<endl;
			
			
			seedha[i+1]+=1;
			seedha[index+1]+=-1;
			if(i>=1)
			{
				index=uppersearch(sufix,i-1,sufix[i]+arr[i]);
				// cout<<"ulta"<<" "<<index<<endl;
				ulta[i-1]+=1;
				if(index-1!=-1)
					ulta[index-1]+=-1;
			}
			
		}
		for(ll i=1;i<n;i++)
		{
			seedha[i]+=seedha[i-1];
		}
		for(ll i=n-2;i>=0;i--)
			ulta[i]+=ulta[i+1];
		for(ll i=0;i<n;i++)
			cout<<seedha[i]+ulta[i]<<" ";
		// cout<<endl;


		cout<<endl;

	}

	return 0;
}