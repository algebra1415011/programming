#include <bits/stdc++.h>
	#define  ll long long int 
	using namespace std;
	
	
	
	
	 
	int main()
	{
		string s1;
		
		cin>>s1;
		ll high=s1.length();
		// cout<<s1<<s1.highgth()<<endl;
		ll low=1;
		
		ll mid=0;
		
		ll flag=0;
		ll ans=s1.length();
		while(low<=high)
		{
			mid=(low+high)/2;
			map <ll,ll> mp;
			for(ll i=0;i<mid;i++)
			{
				
				mp[s1[i]-'a']++;
			}
			// cout<<low<<" "<<mid<<" "<<high<<endl;
			for(ll i=1;i<=(s1.length()-mid);i++)
			{
				// mp[s1[i-1]-'a']--;
				mp[s1[i+mid-1]-'a']++;
			}
			flag=0;
			// cout<<s1.length()-(mid+1)<<endl;
			for(ll i=0;i<=25;i++)
			{
				// cout<<mp[i]<<" ";
				if(mp[i]>=(s1.length()-mid+1))
				{
					flag=1;
				}
			}
			// cout<<endl;
			if(flag)
			{
				ans=min(ans,mid);
				high=mid-1;


			}
			else
			{
				low=mid+1;
			}


		}

		cout<<ans<<endl;
	 
	} 
	 