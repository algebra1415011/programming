#include <bits/stdc++.h>
		#define ll long long int
		#define inf 1e18
		using namespace std;
		vector<ll> v1;
		
		int main()
		{
			ll t,n;
			cin>>t;
			char k;
 
			while(t--)
			{
				cin>>n;
				string s[2];
				cin>>s[0];
				cin>>s[1];
				ll flag1=0;
				ll flag2=0;
				v1.clear();
				
					ll flag=0;
					ll ans=0;
					for(ll i=0;i<n;i++)
					{
						if(s[0][i]=='*' && s[1][i]=='*')
							{
								v1.push_back(3);
								flag=1;	
							}	
						else if(s[0][i]=='*')
							{
								v1.push_back(1);
								flag1=1;
 
							}
						else if(s[1][i]=='*')
						{
							v1.push_back(2);
							flag2=1;
						}		
 						
					}
					if(flag)
						ans++;
					else if(flag1 and flag2)
						ans++;
					//cout<<"ans"<<v1.size()<<endl;
					ll c1=0;
					ll c2=0;
					if(v1[0]==3)
						c1=1,c2=1;
					else if(v1[0]==2)
						c2=1;
					else if(v1[0]==1)
						c1=1;
					for(ll i=1;i<v1.size();i++)
					{
						if(v1[i]==1)
						{
							if(c1)
							{
								ans++;
								c2=0;
							}
							c1=1;
							//cout<<ans<<endl;	
						}
						else if(v1[i]==2)
						{
							if(c2)
							{
								ans++;
								c1=0;

							}	
							c2=1;
							//cout<<ans<<endl;

						}
						else if(v1[i]==3)
						{
							if(c1 or c2)
							{	
								ans++;
								c1=1;
								c2=1;
							}
							//cout<<ans<<endl;	
						}
					}
					cout<<ans<<endl;
				}	
				
				
		} 