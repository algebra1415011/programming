#include <bits/stdc++.h>
#define ll long long int
using namespace std;
bool check[1000];
ll prime[100];
ll c;
void sieve()
{
	for(ll i=2;i<=52;i++)
	{
		if(!check[i])
			{
				for(ll j=2*i;j<=100;j=j+i)
				{
					check[j]=true;
				}
				c++;
			}	
	}
	ll k=0;
	for(ll i=2;i<50;i++)
	{
		if(!check[i])
			prime[k++]=i;
	}
	//ll ans=1;
	/*for(ll i=1;i<=15;i++)
		{cout<<prime[i]<<" ";

		//ans=ans*prime[i];
	}
	//cout<<"ans"<<ans;
		//cout<<endl; 
	//cout<<"c"<<c<<endl;*/
}
ll bitsd(ll mid)
{
	ll maxi=(1<<15);
	
	ll res;

	ll rank=0;
	for(ll mask=1;mask<maxi;mask++)
	    {
	    	ll c=0;
	    	 res=mask;
	    	 ll j=0;
	    	 ll hu=1;
	    	while(res)
	    	{
	    		if(res%2==1)
	    			{
	    				c++;
	    				hu=hu*prime[j];

	    			}
	    		j++;		
	    		res/=2;
	    	}
	    	
	        
	        //cout<<hu<<endl;
	        if(c%2==0)
               	{
              		rank-=mid/hu;
              	}	
              	else
              	{
              		rank+=mid/hu;
              	}
	    }
	    return rank;
}	    

 




int main()
{

	sieve();
	ll n,m;
	//bit(15);
	cin>>n;
	
	ll rank;
	for(ll i=0;i<n;i++)
	{
		cin>>m;
		ll ans=1e18;
		//cout<<"hello"<<endl;
		ll start=0;
		ll end=1e18;
		ll mid;
		while(end>=start)
		{
			mid=(start+end)/2;
			rank=bitsd(mid);
			//cout<<rank<<endl;
			if(rank>=m)
				{
					end=mid-1;
					ans=min(ans,mid);
				}	
			else
				start=mid+1;
		}
		cout<<ans<<endl;

	}
	return 0;
}