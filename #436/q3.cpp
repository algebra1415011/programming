#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll a,b,f,k;
	cin>>a>>b>>f>>k;
	ll journey=0;
	ll flag=0;
	ll temp=b;
	for(ll i=0;i<k;i++)
	{
		if(i%2==0)
		{
			if(temp<f)
			{
				cout<<-1<<endl;
				exit(0);
			}
			else
				temp-=f;
			if((i==(k-1) and temp>=(a-f)) or (temp>=(2*(a-f))))
				temp-=(a-f);
			else
			{
				temp=b;
				temp-=(a-f);
				journey++;
			}
			
		}
		else
		{
				if(temp<(a-f))
				{
					cout<<-1<<endl;
					exit(0);
				}
				else
					temp-=(a-f);
				if((i==(k-1) and temp>=f) or (temp>=2*f))
					temp-=f;
				else
				{
					temp=b;
					temp-=f;
					journey++;
				}
				

		}
		if(temp<0)
			{
				cout<<-1<<endl;
				exit(0);
			}	
	}
	cout<<journey<<endl;
	return 0;
}