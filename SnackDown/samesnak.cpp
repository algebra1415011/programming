#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{

	ll t,xa1,xa2,xb1,xb2,ya1,ya2,yb1,yb2;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&xa1,&ya1,&xa2,&ya2);
		scanf("%lld%lld%lld%lld",&xb1,&yb1,&xb2,&yb2);
		
		if((xa1==xb1 && ya1==yb1) || (xa1==xb2 && ya1==yb2) || (xa2==xb1 && ya2==yb1) || (xa2==xb2 && ya2==yb2))
			cout<<"yes"<<endl;
		else if(xa1==xa2 && xa2==xb1 && xb1==xb2)
		{
			//cout<<"jk"<<endl;
			if((ya1>yb1 && ya1>yb2 && ya2>yb1 && ya2>yb2) || (ya1<yb1 && ya1<yb2 && ya2<yb1 && ya2<yb2))
				cout<<"no"<<endl;
			else
				cout<<"yes"<<endl;
		}
		else if(ya1==ya2 && ya2==yb1 && yb1==yb2)
		{	
			//cout<<"he"<<endl;	
			if((xa1>xb1 && xa1>xb2 && xa2>xb1 && xa2>xb2) || (xa1<xb1 && xa1<xb2 && xa2<xb1 && xa2<xb2))
				cout<<"no"<<endl;
			else
				cout<<"yes"<<endl;
		}
		else
			{
				//cout<<"kk"<<endl;
				cout<<"no"<<endl;

			}	

	}
}